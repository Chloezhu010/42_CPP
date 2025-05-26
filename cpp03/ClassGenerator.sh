#!/bin/bash

CLASS_NAME=$1
UPPER_NAME=$(echo "$CLASS_NAME" | tr '[:lower:]' '[:upper:]')

# Header file
cat > "${CLASS_NAME}.hpp" <<EOF
#ifndef ${UPPER_NAME}_HPP
#define ${UPPER_NAME}_HPP

#include <iostream>

class ${CLASS_NAME}
{
    private:
        // Add member variables here
    public:
        /* constructors */
        ${CLASS_NAME}();                              
        ${CLASS_NAME}(const ${CLASS_NAME}& other);    
        
        /* operator overload */
        ${CLASS_NAME}& operator=(const ${CLASS_NAME}& other); 
        
        /* destructor */
        ~${CLASS_NAME}();                            
};

#endif
EOF

# Source file
cat > "${CLASS_NAME}.cpp" <<EOF
#include "${CLASS_NAME}.hpp"

${CLASS_NAME}::${CLASS_NAME}()
{
    std::cout << "${CLASS_NAME}: Default constructor called" << std::endl;
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other)
{
    std::cout << "${CLASS_NAME}: Copy constructor called" << std::endl;
    *this = other;
}

${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& other)
{
    std::cout << "${CLASS_NAME}: Copy assignment operator called" << std::endl;
    if (this != &other) {
        // Copy member variables
    }
    return *this;
}

${CLASS_NAME}::~${CLASS_NAME}()
{
    std::cout << "${CLASS_NAME}: Destructor called" << std::endl;
}
EOF

echo "Created ${CLASS_NAME}.hpp and ${CLASS_NAME}.cpp"
