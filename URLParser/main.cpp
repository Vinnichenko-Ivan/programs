
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<ctime>
#include<map>

using namespace std;

class URLParse
{	
	private:
		string URL;
		string scheme;
		string login;
		string password;
		string host;
		string URLPath;
		vector<pair<string,string>> parametrs;
		string URLFragments;
		string port;
	public:
		void parse();
		void build();
		void reset();
		void setPort(string data);
		void setURL(string data);
		void setSheme(string data);
		void setLogin(string data);
		void setPassword(string data);
		void setHost(string data);
		void setURLPath(string data);
		void setParametrs(vector<pair<string,string>> data);
		void setURLFragment(string data);
		string getURL();
		string getSheme();
		string getLogin();
		string getPassword();
		string getHost();
		string getURLPath();
		vector<pair<string,string>> getParametrs();
		string getURIFragment();
		string getPort();
};

void URLParse::reset()
{
	URL = "";
	scheme = "";
	login = "";
	password = "";
	host = "";
	URLPath = "";
	parametrs.clear();
	URLFragments = "";
	port = "";
}

void URLParse::build()
{
	reset();
	int flag = 0;
	for(int i = 0; i < URL.size(); i++)
	{
		if(URL[i] = ':')
		{
			flag = 1;
		}

		if(flag == 0)
		{
			scheme += URL[i];	
		}
	}
}

void URLParse::build()
{
	URL = "";
	URL += scheme;
	URL += ":";
	URL += "//";
	if(host != "")
	{
		if (login != "")
		{
			URL += login;
			if(password != "")
			{
				URL += ":";
				URL += password;
			}
			URL += "@";
		}
		URL += host;
		if(port != "")
		{
			URL += ":";
			URL += port;
		}
	}

	if(URLPath != "")
	{
		URL += URLPath;
	}

	if(parametrs.size() != 0)
	{
		URL += "?";
		URL += parametrs[0].first;
		URL += "=";
		URL += parametrs[0].second;
		for(int i = 0; i < parametrs.size(); i++)
		{
			URL += "&";
			URL += parametrs[0].first;
			URL += "=";
			URL += parametrs[0].second;			
		}
	}

	if(URLFragments != "")
	{
		URL += "#";
		URL += URLFragments;
	}
}

void URLParse::setPort(string data)
{
	port = data;
}

string URLParse::getPort()
{
	return port;
}

void URLParse::setURL(string data)
{
	URL = data;
}

void URLParse::setSheme(string data)
{
	scheme = data;
}

void URLParse::setLogin(string data)
{
	login = data;
}

void URLParse::setPassword(string data)
{
	password = data;
}

void URLParse::setHost(string data)
{
	host = data;
}

void URLParse::setURLPath(string data)
{
	URLPath = data;
}

void URLParse::setParametrs(vector<pair<string,string>> data)
{
	parametrs = data;
}

void URLParse::setURLFragment(string data)
{
	URLFragments = data;
}

string URLParse::getURL()
{
	return URL;
}

string URLParse::getSheme()
{
	return scheme;
}

string URLParse::getLogin()
{
	return login;
}

string URLParse::getPassword()
{
	return password;
}

string URLParse::getHost()
{
	return host;
}

string URLParse::getURLPath()
{
	return URLPath;
}

vector<pair<string,string>> URLParse::getParametrs()
{
	return parametrs;
}

string URLParse::getURIFragment()
{
	return URLFragments;
}

int main()
{	
	URLParse parser;
	parser.setSheme("https");
	parser.setHost("ru.wikipedia.org");
	parser.setURLPath("/wiki/URL");
	parser.build();
	cout << parser.getURL() <<endl;
	return 0;
}