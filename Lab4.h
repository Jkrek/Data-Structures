#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <string>

using namespace std;

//BaseClass Declaration
class BaseClass {
protected:
    string title;
    string description;
public:
    //Getters and Setters
    string getTitle();
    string getDescription();
    void setTitle(string title);
    void setDescription(string description);
    //Constructors
    BaseClass(string t, string d);
    BaseClass();
    //Virtual Play Function
    virtual void Play() = 0;
    //Details Function
    void Details();
};

//Movie Declaration
class Movie : public BaseClass {
private:
    string OpeningCredits;
public:
    //Constructors
    Movie(string t, string d, string OC);
    Movie(string OC);
    //Getters and Setters
    std::string getOpeningCredits();
    void setOpeningCredits(string OC);
    //Overriden Play Function
    void Play() override;
    //Details Function
    void Details();
};

//TV show declaration
class TVShow : public BaseClass {
private:
    int SeasonEpisodeRunTime[5][5];
public:
    //Constructors
    TVShow(string t,string d, int tempArray[][5]);
    TVShow(int tempArray[][5]);
    //Getters and Setters
    int getSeasonEpisodeRunTime(int s, int e);
    //Overriden Play Function
    void Play() override;
    //Details Function
    void Details();
};

//Combined Functions
void combinedFunctionMovie(Movie myObj);
void combinedFunctionTVShow(TVShow myObj);


#endif 
