#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct Directory
{
    string dir_;
    int depth_;

    Directory(string dir) : dir_(dir), depth_(0)
    {
        for (string::iterator dir_iter = dir_.begin();
             dir_iter < dir_.end();
             ++dir_iter)
        {
            if (*dir_iter == '/') ++depth_;
        }
    }

    vector<string> getFatherDir() const
    {
        string dir = "";
        vector<string> father_dirs = {};

        for (string::const_iterator dir_iter = dir_.begin(); dir_iter < dir_.end(); ++dir_iter)
        {
            if (*dir_iter == '/' && dir.size() != 0)
            {
                father_dirs.push_back(dir);
            }

            dir += *dir_iter;
        }

        return father_dirs;
    }
};

struct DirectoryDeeper
{
    bool operator()(const Directory &d1, const Directory &d2)
    {
        return d1.depth_ > d2.depth_;
    }
};

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folders)
    {
        priority_queue<Directory, vector<Directory>, DirectoryDeeper> dirs;
        vector<string> remaining_folders = {};
        set<string> father_folders;

        for (string folder : folders)
        {
            dirs.push(Directory(folder));
        }

        while (!dirs.empty())
        {
            cout << dirs.top().dir_ << endl;
            auto father_dirs = dirs.top().getFatherDir();
            for (auto father_dir : father_dirs) cout << father_dir << endl;
            cout << endl;
            dirs.pop();   
        }

        return {};
    }
};

int main()
{
    vector<string> folders = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};

    Solution* obj = new Solution();

    obj->removeSubfolders(folders);

    delete obj;

    return 0;
}