#include<IOstream>
#include<vector>
#include<string>
using namespace std;

float calculate(vector<string> expression);

int main(int argc, char* args) {
    vector<string> my_vector;
    my_vector.push_back("0");
    my_vector.push_back("1");
    my_vector.push_back("2");
    my_vector.push_back("/");
    my_vector.push_back("-");
    cout << "Hello" << endl;
    cout << to_string(calculate(my_vector));
    return 0;
}

float calculate(vector<string> expression) {
    vector<float> stack;
    int expression_size = expression.size();

    for (int i = 0; i<expression_size; i++){
        string current = expression.back();
        expression.pop_back();
        if (current == "+") {
        float A = stack.back(); stack.pop_back();
        float B = stack.back(); stack.pop_back();
        stack.push_back(A+B);
        }
        else if (current == "*")
        {
        float A = stack.back(); stack.pop_back();
        float B = stack.back(); stack.pop_back();
        stack.push_back(A*B);
        }
        else if (current == "-")
        {
        float A = stack.back(); stack.pop_back();
        float B = stack.back(); stack.pop_back();
        stack.push_back(B-A);
        }
        else if (current == "/")
        {
        float A = stack.back(); stack.pop_back();
        float B = stack.back(); stack.pop_back();
        stack.push_back(B/A);
        }
        else {
        stack.push_back(stof(current));
        }
    };

    return stack.back();
    }
