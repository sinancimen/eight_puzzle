#pragma once
#include "MyForm1.h"
#include "states.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <random>

namespace eight_puzzle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//


			visual->Show();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  start_button;
	private: System::Windows::Forms::Button^  pause_button;
	private: System::Windows::Forms::Button^  cancel_button;
	private: System::Windows::Forms::TextBox^  iteration_number_textbox;
	private: System::Windows::Forms::ComboBox^  search_method_list;
	private: System::Windows::Forms::Button^  iterate_button;
	private: System::Windows::Forms::Button^  generate_button;
	private: System::Windows::Forms::TextBox^  method_textbox_static;
	private: System::Windows::Forms::TextBox^  size_textbox_static;
	private: System::Windows::Forms::TextBox^  size_textbox_input;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		MyForm1^ visual = gcnew MyForm1();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->pause_button = (gcnew System::Windows::Forms::Button());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->iteration_number_textbox = (gcnew System::Windows::Forms::TextBox());
			this->search_method_list = (gcnew System::Windows::Forms::ComboBox());
			this->iterate_button = (gcnew System::Windows::Forms::Button());
			this->generate_button = (gcnew System::Windows::Forms::Button());
			this->method_textbox_static = (gcnew System::Windows::Forms::TextBox());
			this->size_textbox_static = (gcnew System::Windows::Forms::TextBox());
			this->size_textbox_input = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// start_button
			// 
			this->start_button->Location = System::Drawing::Point(12, 110);
			this->start_button->Name = L"start_button";
			this->start_button->Size = System::Drawing::Size(75, 23);
			this->start_button->TabIndex = 1;
			this->start_button->Text = L"Start";
			this->start_button->UseVisualStyleBackColor = true;
			// 
			// pause_button
			// 
			this->pause_button->Location = System::Drawing::Point(93, 108);
			this->pause_button->Name = L"pause_button";
			this->pause_button->Size = System::Drawing::Size(75, 23);
			this->pause_button->TabIndex = 2;
			this->pause_button->Text = L"Pause";
			this->pause_button->UseVisualStyleBackColor = true;
			// 
			// cancel_button
			// 
			this->cancel_button->Location = System::Drawing::Point(174, 108);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(75, 23);
			this->cancel_button->TabIndex = 3;
			this->cancel_button->Text = L"Cancel";
			this->cancel_button->UseVisualStyleBackColor = true;
			// 
			// iteration_number_textbox
			// 
			this->iteration_number_textbox->Location = System::Drawing::Point(12, 139);
			this->iteration_number_textbox->Name = L"iteration_number_textbox";
			this->iteration_number_textbox->ReadOnly = true;
			this->iteration_number_textbox->Size = System::Drawing::Size(100, 20);
			this->iteration_number_textbox->TabIndex = 4;
			// 
			// search_method_list
			// 
			this->search_method_list->FormattingEnabled = true;
			this->search_method_list->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"BFS", L"DFS", L"A*" });
			this->search_method_list->Location = System::Drawing::Point(118, 11);
			this->search_method_list->Name = L"search_method_list";
			this->search_method_list->Size = System::Drawing::Size(121, 21);
			this->search_method_list->TabIndex = 5;
			// 
			// iterate_button
			// 
			this->iterate_button->Location = System::Drawing::Point(127, 137);
			this->iterate_button->Name = L"iterate_button";
			this->iterate_button->Size = System::Drawing::Size(112, 23);
			this->iterate_button->TabIndex = 6;
			this->iterate_button->Text = L"Iterate";
			this->iterate_button->UseVisualStyleBackColor = true;
			// 
			// generate_button
			// 
			this->generate_button->Location = System::Drawing::Point(76, 165);
			this->generate_button->Name = L"generate_button";
			this->generate_button->Size = System::Drawing::Size(115, 23);
			this->generate_button->TabIndex = 7;
			this->generate_button->Text = L"Generate Puzzle";
			this->generate_button->UseVisualStyleBackColor = true;
			this->generate_button->Click += gcnew System::EventHandler(this, &MyForm::generate_Click);
			// 
			// method_textbox_static
			// 
			this->method_textbox_static->Location = System::Drawing::Point(31, 11);
			this->method_textbox_static->Name = L"method_textbox_static";
			this->method_textbox_static->ReadOnly = true;
			this->method_textbox_static->Size = System::Drawing::Size(56, 20);
			this->method_textbox_static->TabIndex = 8;
			this->method_textbox_static->Text = L"Method:";
			// 
			// size_textbox_static
			// 
			this->size_textbox_static->Location = System::Drawing::Point(31, 55);
			this->size_textbox_static->Name = L"size_textbox_static";
			this->size_textbox_static->ReadOnly = true;
			this->size_textbox_static->Size = System::Drawing::Size(54, 20);
			this->size_textbox_static->TabIndex = 9;
			this->size_textbox_static->Text = L"Size:";
			// 
			// size_textbox_input
			// 
			this->size_textbox_input->Location = System::Drawing::Point(127, 55);
			this->size_textbox_input->Name = L"size_textbox_input";
			this->size_textbox_input->Size = System::Drawing::Size(100, 20);
			this->size_textbox_input->TabIndex = 10;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(256, 200);
			this->Controls->Add(this->size_textbox_input);
			this->Controls->Add(this->size_textbox_static);
			this->Controls->Add(this->method_textbox_static);
			this->Controls->Add(this->generate_button);
			this->Controls->Add(this->iterate_button);
			this->Controls->Add(this->search_method_list);
			this->Controls->Add(this->iteration_number_textbox);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->pause_button);
			this->Controls->Add(this->start_button);
			this->Name = L"MyForm";
			this->Text = L"Control GUI";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void generate_Click(System::Object^  sender, System::EventArgs^  e) {

		System::String^ size_string = this->size_textbox_input->Text;
		int size_int = int::Parse(size_string);
		int size_squared = size_int * size_int;
		visual->changeSize(size_int);

		array<System::Windows::Forms::ListViewItem^>^ DataList = gcnew array< System::Windows::Forms::ListViewItem^>(size_squared);
		std::vector<int> RandomList;
		for (int i = 0; i < size_squared; i++)
		{
			RandomList.push_back(i);
		}
		std::random_shuffle(std::begin(RandomList), std::end(RandomList));
		for (int i = 0; i < size_squared; i++)
		{
			int random_value = RandomList.at(i);
			std::string str;
			if (random_value == 0)
				str = "";
			else
				str = std::to_string(random_value);
			System::String^ str2 = gcnew String(str.c_str());
			DataList[i] = (gcnew System::Windows::Forms::ListViewItem(str2));
		}
		visual->changeItems(DataList);
		find_solution_bfs(RandomList);
	};
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
