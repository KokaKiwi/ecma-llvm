#ifndef ECMA_EXCEPTION_H_
#define ECMA_EXCEPTION_H_

#include <memory>
#include <string>
#include <vector>
#include <utility>

#define ANSI_COLOR_WHITE        "\x1b[00m"
#define ANSI_COLOR_GREY         "\x1b[30m"
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_COLOR_MAGENTA      "\x1b[35m"
#define ANSI_COLOR_CYAN         "\x1b[36m"
#define ANSI_COLOR_BOLD_GREY    "\x1b[1;30m"
#define ANSI_COLOR_BOLD_RED     "\x1b[1;31m"
#define ANSI_COLOR_BOLD_GREEN   "\x1b[1;32m"
#define ANSI_COLOR_BOLD_YELLOW  "\x1b[1;33m"
#define ANSI_COLOR_BOLD_BLUE    "\x1b[1;34m"
#define ANSI_COLOR_BOLD_MAGENTA "\x1b[1;35m"
#define ANSI_COLOR_BOLD_CYAN    "\x1b[1;36m"
#define ANSI_COLOR_BOLD_WHITE   "\x1b[1;37m"
#define ANSI_COLOR_RESET        ANSI_COLOR_WHITE

namespace ecma
{
    namespace utils
    {
        class Messages
        {
        public:
            typedef std::pair<uint, uint> Position;

            enum class ReportType
            {
                Warning,
                Error,
            };

            inline Messages()
                : warning(0)
                , error(0)
                , colorsEnabled(true)
            {}

            inline static std::shared_ptr<Messages> GetInstancePtr()
            {
                static std::shared_ptr<Messages> instance(new Messages);
                return instance;
            }

            inline static Messages &GetInstance()
            {
                return *GetInstancePtr();
            }

            static void SetSourceName(const std::string &sourceName);
            static const std::string &GetSourceName();

            static void SetSource(const std::string &source);
            static const std::vector<std::string> &GetSource();

            static void Report(ReportType type, const std::string &message, const Position &pos, uint length = 0);

            inline static void ReportError(const std::string &message, const Position &pos, uint length = 0)
            {
                Report(ReportType::Error, message, pos, length);
            }

            inline static void ReportWarning(const std::string &message, const Position &pos, uint length = 0)
            {
                Report(ReportType::Warning, message, pos, length);
            }

            inline static bool HasErrors()
            {
                return GetInstance().error > 0;
            }

            inline static bool HasWarnings()
            {
                return GetInstance().warning > 0;
            }

            inline static bool HasColorsEnabled()
            {
                return GetInstance().colorsEnabled;
            }

            inline static void SetColorsEnabled(bool colorsEnabled)
            {
                GetInstance().colorsEnabled = colorsEnabled;
            }

            inline static void EnableColors()
            {
                SetColorsEnabled(true);
            }

            inline static void DisableColors()
            {
                SetColorsEnabled(false);
            }

            static void Summary();

        private:
            std::string sourceName;
            std::vector<std::string> source;

            uint warning;
            uint error;

            bool colorsEnabled;
        };
    }
}

#endif /* ECMA_EXCEPTION_H_ */
