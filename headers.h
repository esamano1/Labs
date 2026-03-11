// file: headers.h for newanagrams

// Define class AString here!
// See PDF for details
class AString {
    // CODE MISSING HERE!
    public:
        AString();
        Astring(string str);
        string getStringValue();
        void cleanUp();
        void countLetters(int letterCount[]);
        void getAString();

    private:
        string StringValue;
};

// DO NOTE CHANGE THESE AND DO NOT ADD TO THEM!
bool compareCounts(int a[], int b[]);
const int ARRAYSIZE = 26;
