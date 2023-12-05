#include <bits/stdc++.h>
using namespace std;

struct RoutingEntry
{
    string net;
    int masklength;
    string nexthop;
    RoutingEntry(string p, int n, string i) : net(p), masklength(n), nexthop(i) {}
};

string hexa_to_binary(string &hexAddress);
string conversion_to_binary(string &nett);
string longestPrefixMatch(vector<RoutingEntry> &routingTable, string ipAddress);
bool ip_validation(string s);
bool checkHex(string s);

int main()
{
    vector<RoutingEntry> routingTable = {
        {"C4.50.0.0", 12, "A"},
        {"C4.5E.10.0", 20, "B"},
        {"C4.60.0.0", 12, "C"},
        {"C4.68.0.0", 14, "D"},
        {"80.0.0.0", 1, "E"},
        {"40.0.0.0", 2, "F"},
        {"00.0.0.0", 2, "G"},
    };

    for (auto &i : routingTable)
    {
        i.net = conversion_to_binary(i.net);
        cout << "  | "<< i.net <<"   | " << i.masklength << "  |   " <<  i.nexthop << "  | " <<endl;
    }

    int t;
    cout << "Enter number of input: ";
    cin >> t;
    while (t--)
    {
        string ip_add;
        cout << "Enter the destination IP address: ";
        cin >> ip_add;
        if(ip_validation(ip_add))
        {
            ip_add = conversion_to_binary(ip_add);
            cout << ip_add << endl;
            string nxthop = longestPrefixMatch(routingTable, ip_add);
            cout << "Next hop : " << nxthop << endl;
        }
        else
        {
            cout << "Enter valid ip" << endl;
        }


        // ip_add = conversion_to_binary(ip_add);
        // // cout << ip_add << endl;
        // string nxthop = longestPrefixMatch(routingTable, ip_add);
        // cout << "Next hop : " << nxthop << endl;
    }
    return 0;
}

string hexa_to_binary(string &hexAddress)
{
    string binaryIP = "";
    string hexOctet;
    stringstream ss(hexAddress);
    while (getline(ss, hexOctet, '.'))
    {
        int value = stoi(hexOctet, 0, 16);
        // cout << value << " ";
        bitset<8> bits(value);
        // cout << bits << " ";
        binaryIP += bits.to_string();
    }
    return binaryIP;
}

string conversion_to_binary(string &nett)
{
    return hexa_to_binary(nett);
}

string longestPrefixMatch(vector<RoutingEntry> &routingTable, string ipAddress)
{
    string nxthop = "NONE";
    int longest_matched_length = -1;

    for (auto entry : routingTable)
    {
        int temp = 0;
        string x = entry.net;
        for (int i = 0; i < entry.masklength; i++)
        // for (int i = 0; i < int(x.length()); i++)
        {
            if ((x[i]) == (ipAddress[i]))
            {
                temp++;
            }
            else
            {
                break;
            }
        }
        if (longest_matched_length < temp  && temp == entry.masklength)
        {   
            longest_matched_length = temp;
            nxthop = entry.nexthop;
        }
    }
    return nxthop;  
}

bool ip_validation(string s)
{
    int dot = 0;
    string str = "";
    for (size_t i = 0; i < s.length(); i++)
    {
        if(s[i] == '.')
        {
            dot++;
            if (!checkHex(str))
            {
                return false;
            }
            if(str.length()>2)
            {
                return false;
            }
            str = "";
        }
        if(s[i] != '.')
        {
            str += s[i];
        }
       
    }
    return (dot == 3);
}

bool checkHex(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'F') && (ch < 'a' || ch > 'f'))
        {
            return false;
        }
    }
    return true;
}