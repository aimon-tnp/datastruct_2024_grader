#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main(){
    cout << fixed << setprecision(2); // set to 2 decimals

    int N;
    cin >> N;

    map<int, pair<int, int> > rating_each_subject; // {subject : {rating, number_of_students_rated}}
    map<string, pair<int, int> > rating_each_teacher; // {teacher : {rating, number_of_students_rated}}
    for (int i=0;i<N;i++){
        int subject, rating;
        string teacher;
        cin >> subject >> teacher >> rating;
        
        if (rating_each_subject.find(subject) == rating_each_subject.end()){ // key doesn't exist
            rating_each_subject[subject] = make_pair(rating, 1);
        } else {
            rating_each_subject[subject].first += rating;
            rating_each_subject[subject].second += 1;
        }

        if (rating_each_teacher.find(teacher) == rating_each_teacher.end()){ // key doesn't exist
            rating_each_teacher[teacher] = make_pair(rating, 1);
        } else {
            rating_each_teacher[teacher].first += rating;
            rating_each_teacher[teacher].second += 1;
        }
    }

    for (auto &element : rating_each_subject){ // each subject's output
        cout << element.first << " " << (element.second.first + 0.0) / element.second.second << endl;
        // cout << "subject: " << element.first << " r: " << element.second.first << " n: " << element.second.second << endl;
    }
    for (auto &element : rating_each_teacher){ // each teacher's output
        cout << element.first << " " << (element.second.first + 0.0) / element.second.second << endl;
    }

    return 0;
}