// Name: Akash yadav
// Seneca Student ID: 172566218
// Seneca email: ayadav35@myseneca.ca

//
// I confirm that I am the only author of this file and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include "Workstation.h"

namespace sdds
{
  class LineManager
  {
    std::vector<Workstation*> m_activeLine;                // the collection of workstations for the current assembly line
    size_t                    m_cntCustomerOrder { 0u }; // the total number of CustomerOrder objects
    Workstation*              m_firstStation; // points to the first active station on the current line
    // Workstation*              m_firstStation { nullptr}; // points to the first active station on the current line

  public:
    LineManager(const std::string &file, const std::vector<Workstation*>& stations);
    void reorderStations();
    bool run(std::ostream &os);
    void display(std::ostream &os) const;
  };
}
#endif // !SDDS_LINEMANAGER_H