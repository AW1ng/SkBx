#include <fstream>
#include <iostream>
#include <json/json.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;


 size_t write_func(void *ptr, size_t size, size_t nmemb, void *userdata) {
            cout.write( (char * ) ptr, size*nmemb); // just output response to screen
            ((std::string*)userdata)->append((char*)ptr, size * nmemb);
            return size * nmemb;
        }
// size_t write_data(void *ptr, size_t size, size_t nmemb, void *userdata) {
 //       return  ((std::string*)userdata)->append((char*)ptr, size * nmemb);
// }


bool IsIn( char symbol, const string& data ) {
    for( int i = 0; i < data.length(); i++) {
        if( symbol == data[i] ) return true;
    }
    return false;
}
bool GetNextToken(const string& data, const string& delims, int &lastpos, int &nextpos  ) {
    lastpos = nextpos;
    while( IsIn( data[lastpos], delims ) && lastpos < data.length() - 1 ) lastpos++;
    //if( lastpos ) lastpos++;
    if( lastpos >= data.length() ) return false;
    for( int i = lastpos + 1; i < data.length(); i++ ) {
        for( int j = 0; j < delims.length(); j++ ) {
            if( data[i] == delims[j] ) {
                nextpos = i;
                return true;
            }
        }
    }
    nextpos = data.length();
    return true;
}

bool HasWord( const string data, const string word, string delims = " " ) {
    int lpos = 0, npos = 0;
     while( GetNextToken( data, delims, lpos, npos )) {
        string currword;
        //if( npos - lpos > 1 ) 
        currword = data.substr( lpos, npos - lpos );
       // else 
           // currword = "";
        if( currword == word ) return true;
        cout << lpos  <<  " " << npos << " " << currword<< endl;
    }
    return false;
}




class JsonManager {
    protected:
        Json::Value Movie;
        Json::Reader reader;
        string ID = "";
        vector<string> movies;
    public:
        JsonManager() { }
        
        void JsonReader(string path) {
            ifstream json_file(path, std::ifstream::binary);
            json_file >> Movie;
        
            //cout << Movie << endl;
        }

        int readFromStream( string path) {
            Json::Value root;
            std::ifstream ifs(path);

            Json::CharReaderBuilder builder;
            builder["collectComments"] = true;
            JSONCPP_STRING errs;
            if (!parseFromStream(builder, ifs, &root, &errs))
            {
                std::cout << errs << std::endl;
                return EXIT_FAILURE;
            }
            std::cout << root << std::endl;

            return EXIT_SUCCESS;
        }

       /* int readFromString() {
            const std::string rawJson = R"({"Age": 20, "Name": "colin"})";
            const auto rawJsonLength = static_cast<int>(rawJson.length());
            JSONCPP_STRING err;
            Json::Value root;

            Json::CharReaderBuilder builder;
            const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
            if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &root, &err))
            {
                std::cout << "error" << std::endl;
                return EXIT_FAILURE;
            }

            const std::string name = root["Name"].asString();
            const int age = root["Age"].asInt();

            std::cout << name << std::endl;
            std::cout << age << std::endl;
            return EXIT_SUCCESS;
        } */


        Json::Value RecieveDataKP( string parameter = "https://api.kinopoisk.dev/v1.3/movie/random", string X_API = "X-API-KEY: GYB0Z1Y-4E54K2S-MMR0F60-9YWKE75" ) {
            CURL *curl;
            CURLcode res;
            string result;
            Json::Value Jstr;
            char errorBuffer[CURL_ERROR_SIZE];

            // Create the GET request
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, X_API.c_str() );
            headers = curl_slist_append(headers, "accept: application/json");  // Currenlty we support JSON ONLY, required header
            curl = curl_easy_init();

            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, parameter.c_str() );  // 1 = ID of report
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
                curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);     
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
                
                // Attempt to Connect the Server
                res = curl_easy_perform(curl);

                if (res == CURLE_OK) {
                    long http_code = 0;
                    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);
                    if (http_code == 200 && res != CURLE_ABORTED_BY_CALLBACK) {
                        cout << endl << "Success!\n"<< endl;
                    } else {
                        cout << endl << "Error! Code: " << http_code << endl;
                    }
                } else {
                    cout << "Connection Failed! Error: " << errorBuffer << endl;
                }
                // Close the connection
                
               // cout << result << endl; 
                stringstream(result) >> Jstr;
                return Jstr;
                curl_easy_cleanup(curl); 
            } 
            cout <<  "Result ADDIN...";
            return "res";
        }



        void add_movie(string json_name, int amount ) {
            ofstream data(json_name );
            Json::Value vec(Json::arrayValue);
            for( int i = 0; i < amount; i++ ) { Movie["Movies"][i] = RecieveDataKP(); }
            data << Movie << endl; 
        }

        
        void print_names() { 
            for (int i = 0; i < Movie["Movies"].size(); i++  ) {
                for ( int j = 0; j < Movie["Movies"][i]["persons"].size(); j++) {   
                    if ( Movie["Movies"][i]["persons"][j]["enName"] ) 
                        cout << Movie["Movies"][i]["persons"][j]["enName"] << endl;
                    else if ( Movie["Movies"][i]["persons"][j]["name"]  ) {
                        cout << Movie["Movies"][i]["persons"][j]["name"].asString() << endl;
                    } 
                }
            }
        }


        void prof_info( Json::Value info, int i) {
            cout << info.getMemberNames()[i] << "\n";
            for( int j = 0; j <  info["profession"].size(); j++ ) {
                cout <<j+1 << " "<< info["profession"][j]["value"].asString() <<endl;
            } 
        }
        void spouses( Json::Value info, int i ) {
            cout << info.getMemberNames()[i] << ":\n";
            for( int j = 0; j < info["spouses"][0].size(); j++ ) {
                 cout  << info["spouses"][0].getMemberNames()[j] <<" "<< info["spouses"][0][info["spouses"][0].getMemberNames()[j]].asString() <<endl;
            }         
        }

        void facts( Json::Value info, int i) {
            cout << info.getMemberNames()[i] << ":\n";
            for( int j = 0; j <  info["facts"].size(); j++ ) {
                cout <<j+1 << " "<< info["facts"][j]["value"].asString() << endl;
            } 
            cout << endl;
        }

        void  get_actor_info( Json::Value info ) {
            for( int i = 0; i < info.size(); i++ ) {
                if( info.getMemberNames()[i] != "isParse" \
                        && info.getMemberNames()[i] != "movies" \
                        && info.getMemberNames()[i] != "birthPlace" \
                        && info.getMemberNames()[i] != "deathPlace" ) {
                    if( info.getMemberNames()[i] == "facts") { facts( info, i ); cout << endl; }
                    else if( info.getMemberNames()[i] == "profession" ) { prof_info( info, i ); cout << endl; }
                    else if( info.getMemberNames()[i] == "spouses" ) { spouses( info, i ); cout << endl; } 
                    else cout << info.getMemberNames()[i]<< ": " << info[info.getMemberNames()[i]].asString() << endl;
                }
            }

            for( int i = 0; i < info["movies"].size(); i++ ) {
                for (int j = 0; j < info["movies"][i].size(); j++ ) {

                    cout << info["movies"][i].getMemberNames()[j] << ": " << info["movies"][i][info["movies"][i].getMemberNames()[j]].asString() << endl;     
                } 
                cout << endl; 
            }
        }

        void actor_info( string id = "", bool ID_found = true ) {
            Json::Value info; 
            if( id.empty() && ID.empty() ) { cout << "NO ID!" << endl; return; }
            if ( !id.empty() ) {
                info =  RecieveDataKP( "https://api.kinopoisk.dev/v1/person/" + id ); 
                cout <<"Recieving id: " << id << endl;
                get_actor_info(info);
                return;
            }
            else if( ID_found ) {
                cout <<"Recieving ID: " << ID << endl;
                info = RecieveDataKP( "https://api.kinopoisk.dev/v1/person/" + ID );
                get_actor_info(info);
            }
        
        } 


        void find_actor( const string& name, string delim = " ") { 
            string words, ruwords;
            for (int i = 0; i < Movie["Movies"].size(); i++  ) {
                for ( int j = 0; j < Movie["Movies"][i]["persons"].size(); j++){
                    words = Movie["Movies"][i]["persons"][j]["enName"].asString();
                    ruwords = Movie["Movies"][i]["persons"][j]["name"].asString();
                    int end = words.find(delim);
                    int ruend = ruwords.find(delim);
                    int begin = end + 1; 
                    int rubegin = ruend + 1;
                    if( words.substr(0, end) == name || words.substr(begin, words.length()-1) == name) {
                        ID = Movie["Movies"][i]["persons"][j]["id"].asString(); 
                        cout << Movie["Movies"][i]["persons"][j]["enName"] << endl;

                    } else if( ruwords.substr(0, ruend) == name || ruwords.substr(rubegin, ruwords.length()-1) == name) {
                        ID = Movie["Movies"][i]["persons"][j]["id"].asString();
                        cout << Movie["Movies"][i]["persons"][j]["name"].asString() << endl;
                    }
                }
            }

        } 

      
};


int main() {
    JsonManager manager;
    // manager.readFromStream("rmovie.json");
    //manager.JsonReader("rmovie.json");
    // manager.add_movie("Movies.json", 5);
    manager.JsonReader("Movies.json");
    manager.find_actor("Sacks");
   // manager.actor_info("1959253");
    //manager.actor_info();
    
    
}
