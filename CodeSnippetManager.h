#ifndef CODE_SNIPPET_MANAGER_H
#define CODE_SNIPPET_MANAGER_H



#include <string>
#include <map>


class CodeSnippetManager
{
      private:

           std::map<std::string, std::string> snippets;
      public:

          void addSnippet(const std::string& tag,const std::string& code);
          void retrieveSnippet(const std::string& tag);


          bool saveToFile(const std::string& filename);
          bool loadToFile(const std::string& filename);
};

#endif
