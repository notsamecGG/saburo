#pragma once

#include "common.hpp"


namespace gg::ui::terminal
{
/**
 * @brief Basic prefab from whom other (custom) commands should be derived
 * 
 */
template<typename T>
struct Command
{
    std::string name;

public:
    /**
     * @brief Construct a new Command
     * 
     * @param a_name - command name
     * @param callback - function which will be called when command is activated
     */
    Command(const std::string& a_name, const callback_t& callback) : m_callback(callback), name(a_name) { }
    
    /**
     * @brief Execute given command
     * 
     * @param args - string of argument/s
     * @param notes - pointer to vector of Notes
     */
    void execute(const std::string args, std::vector<T>* notes) { m_callback(args, notes); }

private:
    callback_t m_callback;

    typedef std::function<void(std::string, std::vector<T>*)> callback_t;
};
}