//
//  Picture.h
//  FileSystem
//
//  Created by Zhivko Georgiev on 28.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Picture_h
#define Picture_h

#include "File.h"
class Picture: public File{
protected:
    std::string deviceName;
    std::string quality;
public:
    Picture();
    Picture(std::string, std::string, int, std::vector<char>, int, std::string,
            std::string, std::string);
    void setDeviceName(const std::string&);
    void setQuality(const std::string&);

    const std::string getDeviceName() const;
    const std::string getQuality() const;
};
#endif /* Picture_h */
