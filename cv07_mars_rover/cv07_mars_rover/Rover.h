//
//  Rover.h
//  cv07_mars_rover
//
//  Created by Jaroslav Korčák on 07.11.2024.
//

#include <vector>
#include <algorithm>
#ifndef Rover_h
#define Rover_h
#include <memory>

template<class Source, class Result>
class Rover {
private:
    std::vector<std::unique_ptr<Source>> sources;
public:
    void add(std::unique_ptr<Source>& input);
    
    std::vector<Result> process() {
        std::vector<Result> results;
        std::for_each(
                      sources.begin(),
                      sources.end(),
                      [&results](std::unique_ptr<Source>& source){
                          results.push_back(Result(*source));
                      }
        );
        sources.clear();
        return results;
    };
    
    void printInfo(){
        std::for_each(sources.begin(), sources.end(), [](Source source) {source.printInfo();});
    }
};

template <class Source, class Result>
void Rover<Source, Result>::add(std::unique_ptr<Source>& input) {
    sources.push_back(std::move(input));
}

#endif /* Rover_h */
