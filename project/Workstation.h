// Name: Akash yadav
// Seneca Student ID: 172566218
// Seneca email: ayadav35@myseneca.ca

//
// I confirm that I am the only author of this file and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds
{
  extern std::deque<CustomerOrder> g_pending;
  extern std::deque<CustomerOrder> g_completed;
  extern std::deque<CustomerOrder> g_incomplete;

  class Workstation : public Station
  {
    std::deque<CustomerOrder> m_orders;      // a double ended queue with CustomerOrders
    Workstation *m_pNextStation { nullptr }; // a pointer to the next Workstation on the assembly line.

  public:
    Workstation(const std::string& src) : Station(src) {};
    Workstation(const Workstation&) = delete;
    Workstation(Workstation&&) = delete;
    Workstation& operator=(const Workstation&) = delete;
    Workstation& operator=(Workstation&&) = delete;

    // fills the order at the front of the queue, if there are CustomerOrders in the queue
    void fill(std::ostream& os);

    // attempts to move the order at the front of the queue to the next station in the assembly line
    bool attemptToMoveOrder();

    // stores the address of the referenced Workstation object in the pointer to the m_pNextStation
    void setNextStation(Workstation* station);

    // returns the address of next Workstation
    Workstation* getNextStation() const;

    // nserts the name of the Item for which the current object
    void display(std::ostream& os) const;

    // moves the CustomerOrder referenced in parameter newOrder to the back of the queue
    Workstation& operator+=(CustomerOrder&& newOrder);
  };
}
#endif // !SDDS_WORKSTATION_H