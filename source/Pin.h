#ifndef PIN_H
#define PIN

class Pin
{
  public:
    Pin( int number );
    int getNumber();
    bool getState();
    void set( bool high );
  private:
    int number_;
    bool state;
};

#endif
