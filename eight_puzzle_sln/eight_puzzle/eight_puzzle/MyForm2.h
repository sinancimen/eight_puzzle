#pragma once

namespace eight_puzzle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void setSolverStatusText(System::String^ str)
		{
			this->solver_status_dynamic->Text = str;
		}

		void setNodesExploreText(System::String^ str)
		{
			this->nodes_explored_dynamic->Text = str;
		}

		void setTimePassedText(System::String^ str)
		{
			this->time_passed_dynamic->Text = str;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  nodes_explored_str_static;
	protected:
	private: System::Windows::Forms::TextBox^  nodes_explored_dynamic;
	private: System::Windows::Forms::TextBox^  solver_status_static;
	private: System::Windows::Forms::TextBox^  solver_status_dynamic;
	private: System::Windows::Forms::TextBox^  time_passed_static;
	private: System::Windows::Forms::TextBox^  time_passed_dynamic;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->nodes_explored_str_static = (gcnew System::Windows::Forms::TextBox());
			this->nodes_explored_dynamic = (gcnew System::Windows::Forms::TextBox());
			this->solver_status_static = (gcnew System::Windows::Forms::TextBox());
			this->solver_status_dynamic = (gcnew System::Windows::Forms::TextBox());
			this->time_passed_static = (gcnew System::Windows::Forms::TextBox());
			this->time_passed_dynamic = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// nodes_explored_str_static
			// 
			this->nodes_explored_str_static->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nodes_explored_str_static->Location = System::Drawing::Point(12, 29);
			this->nodes_explored_str_static->Name = L"nodes_explored_str_static";
			this->nodes_explored_str_static->ReadOnly = true;
			this->nodes_explored_str_static->Size = System::Drawing::Size(100, 13);
			this->nodes_explored_str_static->TabIndex = 0;
			this->nodes_explored_str_static->Text = L"Nodes Explored:";
			// 
			// nodes_explored_dynamic
			// 
			this->nodes_explored_dynamic->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nodes_explored_dynamic->Location = System::Drawing::Point(151, 29);
			this->nodes_explored_dynamic->Name = L"nodes_explored_dynamic";
			this->nodes_explored_dynamic->ReadOnly = true;
			this->nodes_explored_dynamic->Size = System::Drawing::Size(100, 13);
			this->nodes_explored_dynamic->TabIndex = 1;
			// 
			// solver_status_static
			// 
			this->solver_status_static->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->solver_status_static->Location = System::Drawing::Point(12, 64);
			this->solver_status_static->Name = L"solver_status_static";
			this->solver_status_static->ReadOnly = true;
			this->solver_status_static->Size = System::Drawing::Size(100, 13);
			this->solver_status_static->TabIndex = 2;
			this->solver_status_static->Text = L"Solver Status";
			// 
			// solver_status_dynamic
			// 
			this->solver_status_dynamic->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->solver_status_dynamic->Location = System::Drawing::Point(151, 64);
			this->solver_status_dynamic->Name = L"solver_status_dynamic";
			this->solver_status_dynamic->ReadOnly = true;
			this->solver_status_dynamic->Size = System::Drawing::Size(100, 13);
			this->solver_status_dynamic->TabIndex = 3;
			this->solver_status_dynamic->TextChanged += gcnew System::EventHandler(this, &MyForm2::solver_status_dynamic_TextChanged);
			// 
			// time_passed_static
			// 
			this->time_passed_static->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->time_passed_static->Location = System::Drawing::Point(12, 110);
			this->time_passed_static->Name = L"time_passed_static";
			this->time_passed_static->ReadOnly = true;
			this->time_passed_static->Size = System::Drawing::Size(100, 13);
			this->time_passed_static->TabIndex = 4;
			this->time_passed_static->Text = L"Time Passed(sec): ";
			// 
			// time_passed_dynamic
			// 
			this->time_passed_dynamic->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->time_passed_dynamic->Location = System::Drawing::Point(151, 110);
			this->time_passed_dynamic->Name = L"time_passed_dynamic";
			this->time_passed_dynamic->ReadOnly = true;
			this->time_passed_dynamic->Size = System::Drawing::Size(100, 13);
			this->time_passed_dynamic->TabIndex = 5;
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->time_passed_dynamic);
			this->Controls->Add(this->time_passed_static);
			this->Controls->Add(this->solver_status_dynamic);
			this->Controls->Add(this->solver_status_static);
			this->Controls->Add(this->nodes_explored_dynamic);
			this->Controls->Add(this->nodes_explored_str_static);
			this->Name = L"MyForm2";
			this->Text = L"Solver";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void solver_status_dynamic_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
