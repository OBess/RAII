#pragma once
#ifndef C_FILE_HPP
#define C_FILE_HPP

// C++
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <mutex>

class c_file
{
public:
   c_file(const std::string &path) : m_file(path, std::ios::app)
   {
      if (!m_file.is_open())
         throw std::runtime_error("unable to open file");
   }
   ~c_file()
   {
      m_file.close();
   }

   std::ofstream &operator<<(const std::string &data)
   {
      std::lock_guard<std::mutex> lock(m_mutex);
      m_file << data;
      return m_file;
   }

private:
   std::ofstream m_file;
   static std::mutex m_mutex;
};

std::mutex c_file::m_mutex;

#endif //C_FILE_HPP