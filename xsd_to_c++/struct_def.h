/*
 * File automatically generated by
 * gengen 1.4 by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef STRUCT_DEF_GEN_CLASS_H
#define STRUCT_DEF_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class struct_def_gen_class
{
 protected:
  string deserialize;
  string deserialize_para_name;
  string deserialize_para_type;
  string members;
  string serialize;
  string serialize_para_name;
  string serialize_para_type;
  string struc_name;

 public:
  struct_def_gen_class()
  {
  }
  
  struct_def_gen_class(const string &_deserialize, const string &_deserialize_para_name, const string &_deserialize_para_type, const string &_members, const string &_serialize, const string &_serialize_para_name, const string &_serialize_para_type, const string &_struc_name) :
    deserialize (_deserialize), deserialize_para_name (_deserialize_para_name), deserialize_para_type (_deserialize_para_type), members (_members), serialize (_serialize), serialize_para_name (_serialize_para_name), serialize_para_type (_serialize_para_type), struc_name (_struc_name)
  {
  }

  virtual ~struct_def_gen_class()
  {
  }

  static void
  generate_string(const string &s, ostream &stream, unsigned int indent)
  {
    if (!indent || s.find('\n') == string::npos)
      {
        stream << s;
        return;
      }

    string::size_type pos;
    string::size_type start = 0;
    string ind (indent, ' ');
    while ( (pos=s.find('\n', start)) != string::npos)
      {
        stream << s.substr (start, (pos+1)-start);
        start = pos+1;
        if (start+1 <= s.size ())
          stream << ind;
      }
    if (start+1 <= s.size ())
      stream << s.substr (start);
  }

  virtual void generate_deserialize(ostream &stream, unsigned int indent) = 0;

  void set_deserialize(const string &_deserialize)
  {
    deserialize = _deserialize;
  }

  void set_deserialize_para_name(const string &_deserialize_para_name)
  {
    deserialize_para_name = _deserialize_para_name;
  }

  void set_deserialize_para_type(const string &_deserialize_para_type)
  {
    deserialize_para_type = _deserialize_para_type;
  }

  virtual void generate_members(ostream &stream, unsigned int indent) = 0;

  void set_members(const string &_members)
  {
    members = _members;
  }

  virtual void generate_serialize(ostream &stream, unsigned int indent) = 0;

  void set_serialize(const string &_serialize)
  {
    serialize = _serialize;
  }

  void set_serialize_para_name(const string &_serialize_para_name)
  {
    serialize_para_name = _serialize_para_name;
  }

  void set_serialize_para_type(const string &_serialize_para_type)
  {
    serialize_para_type = _serialize_para_type;
  }

  void set_struc_name(const string &_struc_name)
  {
    struc_name = _struc_name;
  }

  void generate_struct_def(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "typedef struct ";
    stream << struc_name;
    stream << " {";
    stream << "\n";
    stream << indent_str;
    indent = 4;
    stream << "    ";
    if (members.size () > 0)
      generate_string (members, stream, indent + indent_str.length ());
    else
      generate_members (stream, indent + indent_str.length ());
    indent = 0;
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "    serialize(";
    stream << serialize_para_type;
    stream << " ";
    stream << serialize_para_name;
    stream << ")";
    stream << "\n";
    stream << indent_str;
    stream << "    {";
    stream << "\n";
    stream << indent_str;
    indent = 8;
    stream << "        ";
    if (serialize.size () > 0)
      generate_string (serialize, stream, indent + indent_str.length ());
    else
      generate_serialize (stream, indent + indent_str.length ());
    indent = 0;
    stream << "\n";
    stream << indent_str;
    stream << "    }";
    stream << "\n";
    stream << indent_str;
    stream << "\n";
    stream << indent_str;
    stream << "    deserialize(";
    stream << deserialize_para_type;
    stream << " ";
    stream << deserialize_para_name;
    stream << ")";
    stream << "\n";
    stream << indent_str;
    stream << "    {";
    stream << "\n";
    stream << indent_str;
    indent = 8;
    stream << "        ";
    if (deserialize.size () > 0)
      generate_string (deserialize, stream, indent + indent_str.length ());
    else
      generate_deserialize (stream, indent + indent_str.length ());
    indent = 0;
    stream << "\n";
    stream << indent_str;
    stream << "    }";
    stream << "\n";
    stream << indent_str;
    stream << "}";
    stream << struc_name;
    stream << ";";
    stream << "\n";
    stream << indent_str;
  }
};

#endif // STRUCT_DEF_GEN_CLASS_H
