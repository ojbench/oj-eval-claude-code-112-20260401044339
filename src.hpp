#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <functional>
// WARNING: NO more headers allowed!

using std::pair;
using std::string;
using std::vector;
using std::map;
using std::function;
namespace final {
    class arguments {
    private:
        // WARNING: You cannot add more member variables.
        int _argc;
        char** _argv;
    public:
        arguments() : _argc(0), _argv(nullptr) {}
        explicit arguments(const string& cmd) {
            // Parse the command string by spaces
            vector<string> tokens;
            string current = "";

            for (size_t i = 0; i < cmd.length(); i++) {
                if (cmd[i] == ' ') {
                    if (!current.empty()) {
                        tokens.push_back(current);
                        current = "";
                    }
                } else {
                    current += cmd[i];
                }
            }

            // Add the last token if not empty
            if (!current.empty()) {
                tokens.push_back(current);
            }

            // Set argc
            _argc = tokens.size();

            // Allocate argv array
            if (_argc > 0) {
                _argv = new char*[_argc];

                // Allocate and copy each argument string
                for (int i = 0; i < _argc; i++) {
                    _argv[i] = new char[tokens[i].length() + 1];
                    strcpy(_argv[i], tokens[i].c_str());
                }
            } else {
                _argv = nullptr;
            }
        }
        ~arguments() {
            // Free all allocated memory
            if (_argv != nullptr) {
                for (int i = 0; i < _argc; i++) {
                    delete[] _argv[i];
                }
                delete[] _argv;
            }
        }
        // WARNING: You cannot modify the following functions
        int argc() const { return _argc; }
        char** argv() const { return _argv; }
    };

    // You don't need to modify shell.
    class shell {
    private:
        map<int, arguments> running_list;
    public:
        shell() = default;

        void run(int pid, const string& cmd, const function<void(int, char**)>& invoked) {
            running_list.emplace(pid, cmd);
            invoked(running_list[pid].argc(), running_list[pid].argv());
        }

        int subprocessExit(int pid, int return_value) {
            running_list.erase(pid);
            return return_value;
        }
        vector<int> getRunningList() const {
            vector<int> rt;
            for (auto& pair:running_list)rt.push_back(pair.first);
            return rt;
        }
    };
}
