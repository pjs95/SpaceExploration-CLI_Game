#ifndef ENGINE_H
#define ENGINE_H
#include"iEngine.h"
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
#include"controller.h"

class Engine : public IEngine
{
    std::istream *in;
    std::ostream *out;
    IRepository<Astronaut>* astronauts;
    IRepository<Planet>* planets;
    IMission* mission;

public:
    Engine(std::istream& in, std::ostream& out, IRepository<Astronaut>& astronauts, IRepository<Planet>& planets, IMission& mission)
    {
        this->in = &in;
        this->out = &out;
        this->astronauts = &astronauts;
        this->planets = &planets;
        this->mission = &mission;
    }
    virtual void run() override
    {
        Controller c(*this->astronauts, *this->planets, *this->mission);

        while (true)
        {
            std::string input;
            std::getline(std::cin, input);
            if(input == ("Край") || input == ("End"))
                break;
            std::vector<std::string> args;
            std::stringstream split_stream(input);
            std::string token;
            while (std::getline(split_stream, token, ' ')) {
                args.push_back(token);
            }
            auto command = args[0];
            try {
                if(command == ("ДобавиАстронавт") || command == ("AddAstronaut"))
                {
                    *this->/*std::c*/out << c.addAstronaut(args[1], args[2]);
                }
                else if(command == ("ДобавиПланета") || command == ("AddPlanet"))
                {
                    std::vector<std::string> items;
                    if (args.size() == 3)
                    {
                        std::stringstream split_stream(args[2]);
                        std::string token;
                        while (std::getline(split_stream, token, ',')) {
                            items.push_back(token);
                        }
                    }
                    *this->/*std::c*/out << c.addPlanet(args[1], items);
                }
                else if(command == ("ПенсионирайАстронавт") || command == ("RetireAstronaut"))
                {
                    *this->/*std::c*/out << c.retireAstronaut(args[1]);
                }
                else if(command == ("ИзследвайПланета") || command == ("ExplorePlanet"))
                {
                    *this->/*std::c*/out << c.explorePlanet(args[1]);
                }
                else if(command == ("Отчет") || command == ("Report"))
                {
                    *this->/*std::c*/out << c.report();
                }
                else continue;
            }
            catch (std::exception& e)
            {
                *this->/*std::c*/out << e.what();
            }
        }
    }
};
#endif // ENGINE_H
