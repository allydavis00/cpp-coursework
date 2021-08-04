//-------TEMPERATURE.H------
//----Allyson Davis----
//-----section 2-----

class Temperature {

    public:
        Temperature(double deg = 0, char s = 'C');

        void Input();

        void Show() const;

        bool Set(double deg, char s);

        double GetDegrees() const;
        char GetScale() const;

        bool SetFormat(char f);

        bool Convert(char sc);

        int Compare (const Temperature& d) const;

        double DegKelvin() const;

        void Increment(int deg, char sc); //extra credit

    private:

        //Celsius = (Fahrenheit - 32) X (5/9)
        //(or) Fahrenheit = (Celsius X 9/5) + 32
        //Celsius = Kelvin - 273.15
        double degree;  //not below O K
        char scale;     //F, C, or K
        char format;
};