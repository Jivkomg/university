//
//  Folder.cpp
//  FileSystem
//
//  Created by Zhivko Georgiev on 28.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Folder.h"
Folder::Folder() {
    size = 255;
}

void Folder::setFiles(const std::vector<File*>& newFiles) {
    files = newFiles;
}

const std::vector<File*> Folder::getFiles() const {
    return files;
}

