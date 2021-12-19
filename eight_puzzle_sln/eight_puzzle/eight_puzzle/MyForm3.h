#pragma once

namespace eight_puzzle {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void setNodesExploredText(System::String^ str)
		{
			this->node_expansion_textbox->Text = str;
		}

		void setMemoryUsage(System::String^ str)
		{
			this->mc_nodes_stored_textbox->Text = str;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  mc_status_textbox;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  node_expansion_textbox;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  mc_nodes_stored_textbox;

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
			this->mc_status_textbox = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->node_expansion_textbox = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->mc_nodes_stored_textbox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// mc_status_textbox
			// 
			this->mc_status_textbox->Location = System::Drawing::Point(194, 8);
			this->mc_status_textbox->Name = L"mc_status_textbox";
			this->mc_status_textbox->ReadOnly = true;
			this->mc_status_textbox->Size = System::Drawing::Size(100, 20);
			this->mc_status_textbox->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Location = System::Drawing::Point(9, 15);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(100, 13);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"Status:";
			// 
			// textBox3
			// 
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Location = System::Drawing::Point(9, 64);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(137, 13);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"Average Node Expansion:";
			// 
			// node_expansion_textbox
			// 
			this->node_expansion_textbox->Location = System::Drawing::Point(194, 61);
			this->node_expansion_textbox->Name = L"node_expansion_textbox";
			this->node_expansion_textbox->ReadOnly = true;
			this->node_expansion_textbox->Size = System::Drawing::Size(100, 20);
			this->node_expansion_textbox->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(9, 117);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(126, 13);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"Average nodes stored:";
			// 
			// mc_nodes_stored_textbox
			// 
			this->mc_nodes_stored_textbox->Location = System::Drawing::Point(194, 117);
			this->mc_nodes_stored_textbox->Name = L"mc_nodes_stored_textbox";
			this->mc_nodes_stored_textbox->ReadOnly = true;
			this->mc_nodes_stored_textbox->Size = System::Drawing::Size(100, 20);
			this->mc_nodes_stored_textbox->TabIndex = 5;
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 187);
			this->Controls->Add(this->mc_nodes_stored_textbox);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->node_expansion_textbox);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->mc_status_textbox);
			this->Name = L"MyForm3";
			this->Text = L"Monte-Carlo Simulation";
			this->Load += gcnew System::EventHandler(this, &MyForm3::MyForm3_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm3_Load(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
