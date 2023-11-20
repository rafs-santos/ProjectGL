#ifndef LAYER_H
#define LAYER_H

#include <string>
namespace SolarB{
    class Layer {
    public:
        Layer() = default;
        Layer(const std::string& name) : m_name{name} {}
        
        // Rule of five (Need to understand this)
        //https://en.cppreference.com/w/cpp/language/rule_of_three
        Layer(const Layer&)  = default;
        Layer(Layer&&) = default;
        Layer& operator=(const Layer&) = default;
        Layer& operator=(Layer&&) = default;
        virtual ~Layer() = default;

        virtual void init();
        virtual void update();
        virtual void render();
        virtual void shutdown();


    private:
        std::string m_name;
    };
}
#endif