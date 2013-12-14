#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "ecma/utils/messages.h"

using namespace ecma;
using namespace ecma::utils;

void Messages::SetSourceName(const std::string &sourceName)
{
    GetInstance().sourceName = sourceName;
}

const std::string &Messages::GetSourceName()
{
    return GetInstance().sourceName;
}

void Messages::SetSource(const std::string &source)
{
    std::vector<std::string> lines;
    std::istringstream ss(source + "\n");

    for (std::string line; std::getline(ss, line); )
    {
        lines.push_back(line);
    }

    GetInstance().source = lines;
}

const std::vector<std::string> &Messages::GetSource()
{
    return GetInstance().source;
}

void Messages::Report(Messages::ReportType type, const std::string &message, const Messages::Position &pos, uint length)
{
    std::string color, label;

    switch (type)
    {
        case Messages::ReportType::Warning:
            color = ANSI_COLOR_BOLD_MAGENTA;
            label = "warning";
            GetInstance().warning++;
            break;

        case Messages::ReportType::Error:
            color = ANSI_COLOR_BOLD_RED;
            label = "error";
            GetInstance().error++;
            break;

        default:
            color = ANSI_COLOR_BOLD_GREY;
            label = "note";
            break;
    }

    std::cerr << ANSI_COLOR_BOLD_WHITE;
    std::cerr << GetSourceName() << ":" << pos.first << ":" << pos.second << ": ";
    std::cerr << color << label << ": ";
    std::cerr << ANSI_COLOR_BOLD_WHITE << message << std::endl;
    std::cerr << ANSI_COLOR_RESET;

    uint i = pos.first - 1;
    if (i < GetInstance().source.size())
    {
        std::string line = GetInstance().source[i];
        std::string pad(pos.second - 1, ' ');
        std::string size(length, '~');

        std::cerr << line << std::endl;
        std::cerr << pad << ANSI_COLOR_BOLD_GREEN << "^" << size << std::endl;
        std::cerr << ANSI_COLOR_RESET;
    }
}

void Messages::Summary()
{
    uint warning = GetInstance().warning;
    uint error = GetInstance().error;

    if (warning > 0)
    {
        std::cerr << warning << " " << (warning == 1 ? "warning" : "warnings") << " generated." << std::endl;
    }

    if (error > 0)
    {
        std::cerr << error << " " << (error == 1 ? "error" : "errors") << " generated." << std::endl;
    }
}
