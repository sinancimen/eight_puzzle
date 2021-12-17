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
	std::vector<int> list_to_be_solved;
	std::vector<std::vector<std::vector<int>>> result_sequence;
	int iteration_number;

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
	private: System::Windows::Forms::Button^  solve_button;
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
			this->solve_button = (gcnew System::Windows::Forms::Button());
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
			this->iteration_number_textbox->Text = L"0";
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
			this->iterate_button->Click += gcnew System::EventHandler(this, &MyForm::iterate_Click);
			// 
			// generate_button
			// 
			this->generate_button->Location = System::Drawing::Point(12, 165);
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
			// solve_button
			// 
			this->solve_button->Location = System::Drawing::Point(133, 165);
			this->solve_button->Name = L"solve_button";
			this->solve_button->Size = System::Drawing::Size(106, 23);
			this->solve_button->TabIndex = 11;
			this->solve_button->Text = L"Solve!";
			this->solve_button->UseVisualStyleBackColor = true;
			this->solve_button->Click += gcnew System::EventHandler(this, &MyForm::solve_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(256, 200);
			this->Controls->Add(this->solve_button);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: 


		System::Void generate_Click(System::Object^  sender, System::EventArgs^  e) 
		{
		System::String^ size_string = this->size_textbox_input->Text;
		int size_int = int::Parse(size_string);
		int size_squared = size_int * size_int;
		visual->changeSize(size_int);

		list_to_be_solved.clear();
		for (int i = 0; i < size_squared; i++)
		{
			list_to_be_solved.push_back(i);
		}
		//std::random_shuffle(std::begin(list_to_be_solved), std::end(list_to_be_solved));
		list_to_be_solved = { 3,4,6,1,0,8,7,2,5 };
		show_on_grid_1d(list_to_be_solved);
		iteration_number = 0;
	}

	System::Void solve_Click(System::Object^  sender, System::EventArgs^  e) {

		result_sequence = find_solution_bfs(list_to_be_solved);
	}

	System::Void iterate_Click(System::Object^  sender, System::EventArgs^  e) {

		if (result_sequence.size() == 0)
		{
		}
		else
		{
			std::vector<std::vector<int>> list_to_show_2d = result_sequence.at(0);
			std::vector<int> list_to_show_1d;
			result_sequence.erase(result_sequence.begin());
			for (int i = 0; i < list_to_show_2d.size(); i++)
			{
				for (int j = 0; j < list_to_show_2d.size(); j++)
				{
					list_to_show_1d.push_back(list_to_show_2d.at(i).at(j));
				}
			}
			show_on_grid_1d(list_to_show_1d);
			iteration_number += 1;
			std::string iteration_number_str = std::to_string(iteration_number);
			System::String^ iteration_number_sstr = gcnew String(iteration_number_str.c_str());
			iteration_number_textbox->Text = iteration_number_sstr;
		}
		
	}

	System::Void show_on_grid_1d(std::vector<int> List)
	{
		int size_squared = List.size();
		array<System::Windows::Forms::ListViewItem^>^ DataList = gcnew array< System::Windows::Forms::ListViewItem^>(size_squared);
		for (int i = 0; i < size_squared; i++)
		{
			int random_value = List.at(i);
			std::string str;
			if (random_value == 0)
				str = "";
			else
				str = std::to_string(random_value);
			System::String^ str2 = gcnew String(str.c_str());
			DataList[i] = (gcnew System::Windows::Forms::ListViewItem(str2));
		}
		visual->changeItems(DataList);
		visual->Show();
	};

};
}
