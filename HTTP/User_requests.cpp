#include <iostream>
#include <cpr/cpr.h>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;



string MapToString( const map< string , string >& m ) {
    string result = "";
    for( auto item : m ) {
        result += item.first + "\t:\t" + item.second + "\n";
        }
    return result;
    }

ostream& operator<<(ostream &os , const map< string , string >& m) {
    string result = MapToString( m );
    return os << result << endl;
    }

ostream& operator<<(ostream &os , const vector< string >& m) {
    string result = "";
    for( int i = 0 ; i < m.size() ; i++ ) 
        result += to_string( i ) + "\t" + m[i] + "\n" ;
    return os << result << endl;
    }




class Requester {
    protected:
        cpr::Response R;
    public:
        Requester() {
            std::cout <<"HELLO!\n";
        }
        void ProceedGet( std::string url = "http://httpbin.org/headers" ) {
            R = cpr::Get(cpr::Url(url),
		    cpr::Header({ {"user-agent",
			"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.203" },
			{"Accept","text/html"} } ));
        }

        void ProceedPost( std::string name = "", std::string city = "", std::string url = "http://httpbin.org/post" ) {
            R = cpr::Post(cpr::Url(url),
		    cpr::Payload({ {"name", name.c_str()}, {"city", city.c_str()}}) );
        }

        void ProceedPut(std::string url = "http://httpbin.org/put" ) {
            R = cpr::Put( cpr::Url(url), 
            cpr::Payload{ {"key", "value"} } );
        }

        void DeleteReq( std::string url = "https://httpbin.org/delete") {
            R = cpr::Delete( cpr::Url(url) );
        }

        void ProceedPatch(std::string url = "https://httpbin.org/patch") {
            R = cpr::Patch( cpr::Url(url) );
        }

        void GetHead( std::string url = "http://httpbin.org/html" ) { // 2
            // // std::fstream text(url);
            // text.open(url, std::ios::in );
            R = cpr::Get(cpr::Url(url),
		    cpr::Header({  {"Accept","text/html"} } ));
            std::cout << std::endl;
            int a = R.text.find("<h1>");
            int b = R.text.find("</h1>");
            int size = b - a;
            std::cout <<"sizea " << a << " " << "sizeb " << b << std::endl;
            for(int i = a; i < b; i++ ) {
                std::cout << R.text[i];
            }
        }

        void ReqWithArgs( std::string url = "http://httpbin.org/" ) { // 3 string get_args = "", string post_args = "", 
            vector<string> Keys;
            vector<string> Values;

            string request;
            int i = 0;
            map<string, string> KVMap;

            do {
                cin >> request;
                if( request == "get" || request == "post") break;
                if( i % 2 == 0 ) Keys.push_back(request);
                else if( (i % 2 != 0 && request == "get") || request == "post" ) Values.push_back("empty");
                else Values.push_back(request);
                i++;
            } while ( true );

            
            cpr::Parameters param;
            string line, EndFigure = "&";
            

            if( request == "get" ) {
                cout << "GET IT!\n";
                for( int i = 0; i < Keys.size() && i < Values.size(); i++ ) {
                    pair< string, string > TempPair( Keys[i], Values[i] );
                    KVMap[ TempPair.first ] = TempPair.second;
                }
                for( map<string,string>::iterator it = KVMap.begin(); it != KVMap.end(); it++ ) {
                    if (next(it) == KVMap.end() ) EndFigure = "";
                    line += it->first + "=" + it->second + EndFigure;
                }
                cout << line << endl;
                R = cpr::Get( cpr::Url{url + "/get?" + line});

                std::cout <<"URL:" << R.url << std::endl;
            }

            vector<cpr::Pair> TemPair;
            if( request == "post" ) {
                for( int i = 0; i < Keys.size() && i < Values.size(); i++ ) {
                    TemPair.push_back(cpr::Pair((string)Keys[i], (string)Values[i]));
                }
                R = cpr::Post(cpr::Url{url + "/post"}, cpr::Payload(TemPair.begin(), TemPair.end()) );
                         
            }
            
        
        }

        void PrintR() {
            std::cout << R.text << std::endl;
        }


};


int main() {
    Requester Req;
    // Req.ProceedGet(); Req.PrintR();
    // Req.ProceedPost("Alex", "City"); Req.PrintR();
    // Req.ProceedPut(); Req.PrintR();
    // Req.DeleteReq(); Req.PrintR();
    // Req.ProceedPatch(); Req.PrintR();
    Req.GetHead(); Req.PrintR();

    // vector<string> Keys = {"First_key", "Second_key", "Third_key" };
    // vector<string> Values = {"First_val", "Second_val", "Third_val" };
    // cout << Keys << Values;
    // map<string, string> KVMap;
    // for( int i = 0; i < Keys.size() && i < Values.size(); i++ ) {
    //     pair< string, string > TempPair( Keys[i], Values[i] );
    //     cout << TempPair.first + " ; " + TempPair.second << endl;
    //     KVMap[ TempPair.first ] = TempPair.second;
    // }
    // cout << KVMap << endl;

    Req.ReqWithArgs(); Req.PrintR();


}