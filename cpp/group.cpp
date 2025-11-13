#include "group.h"
#include <iostream>
#include <string>
#include <list>
#include "multimedia.h"

using mmptr = std::shared_ptr<Multimedia>;

Group::~Group()
{
    std::cout << "Group "<< name << " is destroyed\n";
}

std::string Group::getName() const
{
   return name;
}

void Group::setName(const std::string& groupName)
{
    name = groupName;
}

std::ostream& Group::display(std::ostream& os) const
{
    os << "Group Name: " << name << std::endl;
    for (const mmptr &m : *this) {
        m->display(os);
        std::cout << std::endl;
    }
    return os;
}