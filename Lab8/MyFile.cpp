#include"MyFile.h"

MyFile::MyFile(const std::string & name)
    : MyItem(name)
{
    
}

MyItem* MyFile::clone() const
{
    return new MyFile(GetName());
}

void MyFile::ls(unsigned int op) const
{
    op++;
    printName(op);
}

void MyFile::cat()
{
    std::cout<<m_content;
}

MyFile& MyFile::operator<<(const std::string& text)
{
    m_content += text + "\n";
    return *this;
}