//
//  Folder.h
//  FileSystem
//
//  Created by Zhivko Georgiev on 28.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Folder_h
#define Folder_h
#include "File.h"
class Folder: public File{
protected:
    std::vector<File*> files;
public:
    Folder();
    
    void setFiles(const std::vector<File*>&);
    const std::vector<File*> getFiles() const;
};

#endif /* Folder_h */
