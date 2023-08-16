// Name: Akash yadav
// Seneca Student ID: 172566218
// Seneca email: ayadav35@myseneca.ca

//
// I confirm that I am the only author of this file and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <string>

namespace sdds {
    class Station {
    private:
        size_t m_id{};
        std::string m_item{};
        std::string m_description{};
        size_t m_serial{};
        size_t m_quantity{ 0 };
        static size_t m_widthField;
         static size_t id_generator;
    public:
        Station() = default;
        
        Station(const std::string str);
       
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}

#endif 