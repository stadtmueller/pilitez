#ifndef PIN_H
#define PIN

class Pin
{
  public:
    Pin( int number );
    int getNumber();
    bool getState();
  private:
    int number_;
    bool state;
};

#endif
