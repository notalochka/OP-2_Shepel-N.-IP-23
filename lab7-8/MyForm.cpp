#include "MyForm.h"
#include "binary.h"
#include <msclr\marshal_cppstd.h>
#include <string>
#include <array>
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

[STAThreadAttribute] 
int main(array <String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	labaratorna7::MyForm form;
	Application::Run(% form);
}


std::string& Convert_String_to_string(String^ s, std::string& ss);
String^ Convert_string_to_String(std::string& ss, String^ s);


System::Void labaratorna7::MyForm::buttonCreateFile1_Click(System::Object^ sender, System::EventArgs^ e)
{	
    String^ input = textBoxFilename1->Text;
    std::string filename = marshal_as<std::string>(input);
    try
    {
        if (input->Length == 0) throw std::runtime_error("Не введена назва вхідного файлу");
        
        createBinaryFile(filename);
        
    }
    catch (const std::string error)
    {
        String^ errorMessage = msclr::interop::marshal_as<String^>(error);
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        textBoxFilename1->Text = String::Empty;
    }
    catch (const std::exception& error)
    {
        String^ errorMessage = gcnew String(error.what());
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        textBoxFilename1->Text = String::Empty;
    }
    
    return System::Void();
}

System::Void labaratorna7::MyForm::buttonReadFile1_Click(System::Object^ sender, System::EventArgs^ e)
{    
    String^ input = textBoxFilename1->Text;
    std::string filename = marshal_as<std::string>(input);
    try
    {
        if (input->Length == 0) throw std::runtime_error("Не введена назва вхідного файлу");
        
        std::string text = readFile(filename);
        String^ outputString = msclr::interop::marshal_as<String^>(text);
        richTextBoxFile1->Text = outputString;
    }
    catch (const std::string error)
    {
        String^ errorMessage = msclr::interop::marshal_as<String^>(error);
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    catch (const std::exception& error)
    {
        String^ errorMessage = gcnew String(error.what());
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        textBoxFilename1->Text = String::Empty;
    }
	return System::Void();
}

System::Void labaratorna7::MyForm::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
    

    try
    {
        String^ input = textBoxName->Text;
        if (input->Length == 0) throw std::runtime_error("Не введено ім'я");
        std::string namestr = marshal_as<std::string>(input);
        Students student;
        char name[100];
        strcpy(name, namestr.c_str());

        String^ input2 = textBoxGroup->Text;
        if (input2->Length == 0) throw std::runtime_error("Не введена група");
        std::string group = marshal_as<std::string>(input2);

        String^ input3 = textBoxDay->Text;
        if (input3->Length == 0) throw std::runtime_error("Не введена дата");
        std::string day = marshal_as<std::string>(input3);

        String^ input4 = textBoxMonth->Text;
        if (input4->Length == 0) throw std::runtime_error("Не введена дата");
        std::string month = marshal_as<std::string>(input4);
                
        String^ input5 = textBoxYear->Text;
        if (input5->Length == 0) throw std::runtime_error("Не введена дата");
        std::string year = marshal_as<std::string>(input5);
        student.setName(name);
        student.setGroup(group);
        student.setDate(day, month, year);

        String^ input6 = textBoxFilename1->Text;
        if (input6->Length == 0) throw std::runtime_error("Не введена назва вхідного файлу");
        std::string filename = marshal_as<std::string>(input6);
        saveToFile(filename, student);

        textBoxName->Text = String::Empty;
        textBoxGroup->Text = String::Empty;
        textBoxDay->Text = String::Empty;
        textBoxMonth->Text = String::Empty;
        textBoxYear->Text = String::Empty;

    }
    catch (const std::string error)
    {
        String^ errorMessage = msclr::interop::marshal_as<String^>(error);
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    catch (const std::exception& error)
    {
        String^ errorMessage = gcnew String(error.what());
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    return System::Void();
}

System::Void labaratorna7::MyForm::buttonRewriteFile2_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input1 = textBoxFilename1->Text;
    std::string filename1 = marshal_as<std::string>(input1);
    String^ input2 = textBoxFilename2->Text;
    std::string filename2 = marshal_as<std::string>(input2);
    try
    {
        if (input1->Length == 0) throw std::runtime_error("Не введена назва вхідного файлу");
        if (input2->Length == 0) throw std::runtime_error("Не введена назва вихідного файлу");

        rewriteFile(filename1, filename2);

    }
    catch (const std::string error)
    {
        String^ errorMessage = msclr::interop::marshal_as<String^>(error);
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    catch (const std::exception& error)
    {
        String^ errorMessage = gcnew String(error.what());
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
	return System::Void();
}

System::Void labaratorna7::MyForm::buttonCreateFile2_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = textBoxFilename2->Text;
    std::string filename = marshal_as<std::string>(input);
    try
    {
        if (input->Length == 0) throw std::runtime_error("Не введена назва вихідного файлу");

        createBinaryFile(filename);

    }
    catch (const std::string error)
    {
        String^ errorMessage = msclr::interop::marshal_as<String^>(error);
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        textBoxFilename2->Text = String::Empty;
    }
    catch (const std::exception& error)
    {
        String^ errorMessage = gcnew String(error.what());
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        textBoxFilename2->Text = String::Empty;
    }
    return System::Void();
}

System::Void labaratorna7::MyForm::buttonReadFile2_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = textBoxFilename2->Text;
    std::string filename = marshal_as<std::string>(input);
    try
    {
        if (input->Length == 0) throw std::runtime_error("Не введена назва вихідного файлу");

        std::string text = readFile(filename);
        String^ outputString = msclr::interop::marshal_as<String^>(text);
        richTextFile2->Text = outputString;
    }
    catch (const std::string error)
    {
        String^ errorMessage = msclr::interop::marshal_as<String^>(error);
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    catch (const std::exception& error)
    {
        String^ errorMessage = gcnew String(error.what());
        MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);

    }
    return System::Void();
}


