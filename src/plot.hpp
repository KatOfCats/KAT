//  ********************************************************************
//  This file is part of KAT - the K-mer Analysis Toolkit.
//
//  KAT is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  KAT is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with KAT.  If not, see <http://www.gnu.org/licenses/>.
//  *******************************************************************

#pragma once

#include <string>
#include <vector>
using std::string;
using std::vector;

#include <boost/exception/exception.hpp>
#include <boost/exception/info.hpp>
#include <boost/filesystem/path.hpp>
namespace bfs = boost::filesystem;
using bfs::path;

#include <kat/pyhelper.hpp>
#include <kat/kat_fs.hpp>
using kat::PyHelper;
using kat::KatFS;

namespace kat {

    typedef boost::error_info<struct KatPlotError,string> KatPlotErrorInfo;
    struct KatPlotException: virtual boost::exception, virtual std::exception { };

    class Plot {

    public:

        enum PlotMode {
            DENSITY,
            PROFILE,
            SPECTRA_CN,
            SPECTRA_HIST,
            SPECTRA_MX,
            COLD
        };

        static bool validatePlotOutputType();

        static int main(int argc, char *argv[]);

        static path getPythonScript(const PlotMode mode);

        static void executePythonPlot(const PlotMode mode, vector<string>& args);

        static void executePythonPlot(const PlotMode mode, int argc, char *argv[]);

    protected:

        static PlotMode parseMode(const string& mode);

        static string helpMessage() {
            return string("Usage: kat plot <mode>\n\n") +
                    "Create K-mer Plots\n\n" +
                    "First argument should be the plot mode you wish to use:\n" \
                    "  * density:         Creates a density plot from a matrix created with the \"comp\" tool or the\n" \
                    "                     \"GCP\" tool.  Typically this is used to compare two K-mer hashes produced\n" \
                    "                     by different NGS reads, or to represent the kmer coverage vs GC count plots.\n" \
                    "  * profile:         Creates a K-mer coverage plot for a single sequence.  Takes in fasta\n" \
                    "                     coverage output from the \"sect\" tool\n" \
                    "  * spectra-cn:      Creates a stacked histogram using a matrix created with the \"comp\" tool.\n" \
                    "                     Typically this is used to compare a jellyfish hash produced from a read set\n" \
                    "                     to a jellyfish hash produced from an assembly. The plot shows the amount of\n" \
                    "                     distinct K-mers absent, as well as the copy number variation present within\n" \
                    "                     the assembly.\n" \
                    "  * spectra-hist:    Creates a K-mer spectra plot for a set of K-mer histograms produced either\n" \
                    "                     by jellyfish-histo or kat-histo.\n" \
                    "  * spectra-mx:      Creates a K-mer spectra plot for a set of K-mer histograms that are derived\n" \
                    "                     from selected rows or columns in a matrix produced by the \"comp\".\n" \
                    "  * cold:            Takes in a stats file produced by \"cold\" and produces a scatter plot of\n" \
                    "                     median read K-mer coverage vs GC% for each contig in the assembly, with\n" \
                    "                     point's size being adjusted by sequence length\n\n"
                    "Options";
        }


    };

}
