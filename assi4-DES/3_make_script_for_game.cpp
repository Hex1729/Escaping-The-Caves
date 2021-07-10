#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ofstream script;
    script.open(" 4_script_for_game.sh");
    script << "#!/usr/bin/expect\n";
    script << "log_file -a f3_crude_outputs.log\n";
    script << "spawn ssh student@65.0.124.36\n";
    string serverp, group, p, infile;
    cout << "Enter your SSH Password : ";
    cin >> serverp;
    cout << "\nEnter your team name : ";
    cin >> group;
    cout << "\nEnter your team pwd : ";
    cin >> p;
    script << "expect  \"student@65.0.124.36's password:\"\n";
    script << "send -- \"";
    script << serverp;
    script << "\\r\"\n\n";
    script << "expect  \"group name:\"\n";
    script << "send -- \"";
    script << group;
    script << "\\r\"\n\n";
    script << "expect  \"word:\"\n";
    script << "send -- \"";
    script << p;
    script << "\\r\"\n\n";
    script << "expect  \"at:\"\n";
    script << "send -- \"4\\r\"\n\n";
    std::ifstream input_file("f2_inputs.txt");
    std::string inp;
    if (input_file.is_open())
    {
        script << "expect  \"> \"\n";
        script << "send -- \"read\\r\"\n\n";
        while (std::getline(input_file, inp))
        {
            script << "expect  \"> \"\n";
            script << "send -- \"";
            script << inp;
            script << "\\r\"\n\n";
            script << "expect  \"> \"\n";
            script << "send -- \"c\\r\"\n\n";
        }
        input_file.close();
    }
    script.close();
}