class Solution 
{
    public:
    vector<double> convertTemperature(double celsius) 
    {
        // Kelvin calculation
        double kelvin = celsius + 273.15;
        
        // Fahrenheit calculation
        double fahrenheit = celsius * 1.80 + 32.00;
        
        return {kelvin, fahrenheit};
    }
};