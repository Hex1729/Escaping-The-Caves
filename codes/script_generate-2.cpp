#include <bits/stdc++.h>
using namespace std;
int main()
{
    // std::ifstream template_script;
    // template_script.open("scripts/script_template.sh"); //open the input file
    // std::stringstream strStream;
    // strStream << template_script.rdbuf();          //read the file
    // std::string script_template = strStream.str(); //str holds the content of the file
    std::ofstream script;
    script.open("get_outputs.sh");
    // script << script_template;
    // script << "\n\n# Autogenerated! Do not edit!\n";
    script << "#!/usr/bin/expect\n";
    script << "log_file -a ssh_outputs.log\n";
    script << "spawn ssh student@65.0.124.36\n";
    string sshpwd, gpname, gppwd, infile;
    sshpwd="caesar";
    gpname="Crewmates";
    gppwd="caesarcypher";
    
   // cout << "Enter your SSH Password : ";
    //cin >> sshpwd;
    //cout << "\nEnter your team name : ";
    //cin >> gpname;
    //cout << "\nEnter your team pwd : ";
    //cin >> gppwd;
    script << "expect  \"student@65.0.124.36's password:\"\n";
    script << "send -- \"";
    script << sshpwd;
    script << "\\r\"\n\n";
    script << "expect  \"group name:\"\n";
    script << "send -- \"";
    script << gpname;
    script << "\\r\"\n\n";
    script << "expect  \"word:\"\n";
    script << "send -- \"";
    script << gppwd;
    script << "\\r\"\n\n";
    script << "expect  \"at:\"\n";
    script << "send -- \"5\\r\"\n\n";
    script << "expect  \">\"\n";
    script << "send -- \"go\\r\"\n\n";
     script << "expect  \">\"\n";
    script << "send -- \"wave\\r\"\n\n";
     script << "expect  \">\"\n";
    script << "send -- \"dive\\r\"\n\n";
     script << "expect  \">\"\n";
    script << "send -- \"go\\r\"\n\n";
    std::ifstream input_random("inputs.txt");
    std::string line;
    if (input_random.is_open())
    {
        script << "expect  \"> \"\n";
        script << "send -- \"read\\r\"\n\n";
        while (std::getline(input_random, line))
        {
            script << "expect  \"> \"\n";
            // script << "send -- \"read\\r\"\n\n";
            // script << "expect  \"> \"\n";
            script << "send -- \"";
            script << line;
            script << "\\r\"\n\n";
            script << "expect  \"> \"\n";
            script << "send -- \"c\\r\"\n\n";
            // script << "expect  \"> \"\n";
            // script << "send -- \"back\\r\"\n\n";
        }
        input_random.close();
    }
    script.close();
    // template_script.close();
}
