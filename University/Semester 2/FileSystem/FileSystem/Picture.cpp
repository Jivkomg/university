//
//  Picture.cpp
//  FileSystem
//
//  Created by Zhivko Georgiev on 28.05.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "Picture.h"


Picture::Picture() { 
    deviceName = '\0';
    quality = '\0';
}

Picture::Picture(std::string n, std::string e, int s, std::vector<char> i, int in, std::string d, std::string device, std::string qual) {
    name = n;
    extension = e;
    dateCreated = d;
    size = s;
    insideNumber = in;
    information = i;
    deviceName = device;
    quality = qual;
}

void Picture::setDeviceName(const std::string& newDevice) {
    deviceName = newDevice;
}

void Picture::setQuality(const std::string& newQuality) {
    quality = newQuality;
}

const std::string Picture::getDeviceName() const { 
    return deviceName;
}

const std::string Picture::getQuality() const { 
    return quality;
}
