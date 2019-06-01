//
//  File.h
//  FileSystem
//
//  Created by Zhivko Georgiev on 28.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef File_h
#define File_h

#include <string>
#include <vector>

class File{
protected:
    std::string name;
    std::string extension;
    int size;
    std::vector<char> information;
    int insideNumber;
    std::string dateCreated;
public:
    File();
    File(std::string, std::string, int, std::vector<char>, int, std::string);
    
    void setName(const std::string&);
    void setExtension(const std::string&);
    void setDateCreated(const std::string&);
    void setSize(const int);
    void setInformation(const std::vector<char>&);
    void setInsideNumber(const int);
    
    
    const std::string getName() const;
    const std::string getExtension() const;
    const std::string getDateCreated() const;
    const std::vector<char> getInformation() const;
    const int getSize(int) const;
    const int getInsideNumber(int) const;
};

#endif /* File_h */
