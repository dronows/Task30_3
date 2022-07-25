
#include "Task30_3.h"
#include <cpr/cpr.h>
#include  "cpr/curl_container.h"
#include <map>
#include <algorithm>

int main()
{
  std::vector <cpr::Pair> pair;
  std::map<std::string, std::string> arguments;

  std::string str1 , str2 ;
  std::cout << "arguments , value : " << std::endl;
  std::cin >> str1 ;
  while (str1 != "get" && str1 != "post") {
    std::cin  >> str2;
    cpr::Pair doc((std::string)str1, (std::string)str2);
    pair.push_back(doc);
    arguments.insert(std::make_pair(str1, str2));
    std::cout << "arguments , value : " << std::endl;
    std::cin >> str1 ;
  }

  if (str1 == "post") {
    std::vector<cpr::Pair>::iterator begin = pair.begin();
    std::vector<cpr::Pair>::iterator end = pair.end();
    cpr::Payload payload(begin, end);
    std::string url = "http://www.httpbin.org/post";
    cpr::Response r = cpr::Post(cpr::Url(url), payload);
    std::cout  << r.text << std::endl;
    std::cout << "status code : " << r.status_code << std::endl;
  } else if (str1 == "get") {
    std::string url = "http://httpbin.org/get?";
    std::map<std::string, std::string>::iterator It = arguments.begin();
    for (   ; It != std::prev(arguments.end()); ++It) {
       url += It->first + '=' + It->second + '&';
    }
    url += It->first + '=' + It->second;
    cpr::Response r = cpr::Get(cpr::Url(url));
    std::cout << r.text << std::endl;
    std::cout << " status code : " << r.status_code << std::endl;
  }
  return 0;
}
