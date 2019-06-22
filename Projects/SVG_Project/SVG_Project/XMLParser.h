//
//  XMLParser.h
//  SVG_Project
//
//  Created by Zhivko Georgiev on 21.06.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef XMLParser_h
#define XMLParser_h

#include <string>
class XMLParser{
//   serialize - from input to stream
//   deserialize - from stream to input
public:
    virtual void deserialize(std::istream&) = 0;
    virtual const std::string getType() const = 0;
    void startSerialize(std::ostream&) const;
    void endSerialize(std::ostream&) const;
//    with parameters for the different shapes
    void serializeWithParameters(std::ostream&, const std::string&, const std::string&) const;
};
#endif /* XMLParser_h */











//    junk
//    const std::string& getFileName(std::string&);
//    static bool readString(const std::string&, std::string&);
//    static bool writeString(const std::string&, std::string&);
//
//    void convertSVGtoCircle(const std::string&, std::vector<std::string>&);
//    void convertSVGtoRectangle(const std::string&, std::vector<std::string>&);
//    void convertSVGtoLine(const std::string&, std::vector<std::string>&);
//
//    bool readFromFile(const std::string&, std::vector<std::string>&);
