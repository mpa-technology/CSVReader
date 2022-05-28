/**
 ** This file is part of the CSVReader project.
 ** Copyright 2022 Maxim Palshin
 ** All rights reserved.
 **
 ** Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **
 ** 1. Redistributions of source code must retain the above copyright notice,
 **    this list of conditions and the following disclaimer.
 **
 ** 2. Redistributions in binary form must reproduce the above copyright
 **    notice, this list of conditions and the following disclaimer in the
 **    documentation and/or other materials provided with the distribution.
 **
 ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 ** EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 ** DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
 ** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 ** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 ** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 ** CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 ** LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 ** OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 ** SUCH DAMAGE.
 **/



#include "CSVReader.hpp"

std::vector<std::string> separateString(const std::string_view &string, char separator){


    auto beginIterator = string.begin();
    auto iterator = string.begin();

    std::vector<std::string>result;

    while ( (iterator =  std::find( iterator, string.end(), separator ) ) != string.end() ) {
        result.push_back( std::string(beginIterator, iterator) );

        beginIterator = iterator + 1;
        iterator++;
    }


    if(beginIterator != iterator || beginIterator != string.end())
        result.push_back(std::string(beginIterator, iterator-1));

    return result;
}



CSVReader::CSVReader(const std::string &fileName)
    : _file(fileName)
{



}

std::vector<std::string> CSVReader::next(){
    std::string line;
    std::getline( _file, line);
    return separateString(line, ',');

}

