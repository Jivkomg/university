//
//  Music.h
//  FileSystem
//
//  Created by Zhivko Georgiev on 28.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Music_h
#define Music_h

#include "File.h"
class Music{
protected:
    std::string artist;
    std::string album;
    std::string songName;
    int year;
public:
    Music();
    Music(std::string, std::string, int, std::vector<char>, int, std::string,
          std::string, std::string, std::string, int);
    
    
};
#endif /* Music_h */
