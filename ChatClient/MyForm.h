#pragma once

namespace ChatClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Runtime::Serialization;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Runtime::Serialization::Formatters;
	using namespace System::Threading;
	using namespace FormatterText;
	using namespace System::IO;

	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			CheckForIllegalCrossThreadCalls = false;
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  IPTextBox;
	private: System::Windows::Forms::Button^  IPConnectButton;


	private: System::Windows::Forms::RichTextBox^  MainTextBox;
	private: System::Windows::Forms::RichTextBox^  SendTextBox;
	private: System::Windows::Forms::Button^  SendButton;



	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Label^  UserNameLabel;
	private: System::Windows::Forms::TextBox^  NickNameTextBox;
	private: System::Windows::Forms::Button^  NickNameSetButton;
	private: System::Windows::Forms::LinkLabel^  FontLinkLabel;
	private: System::Windows::Forms::LinkLabel^  ColorLickLabel;
	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->IPTextBox = (gcnew System::Windows::Forms::TextBox());
			this->IPConnectButton = (gcnew System::Windows::Forms::Button());
			this->MainTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SendTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SendButton = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->UserNameLabel = (gcnew System::Windows::Forms::Label());
			this->NickNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NickNameSetButton = (gcnew System::Windows::Forms::Button());
			this->FontLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->ColorLickLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP adress : ";
			// 
			// IPTextBox
			// 
			this->IPTextBox->Location = System::Drawing::Point(94, 6);
			this->IPTextBox->Name = L"IPTextBox";
			this->IPTextBox->Size = System::Drawing::Size(220, 25);
			this->IPTextBox->TabIndex = 1;
			// 
			// IPConnectButton
			// 
			this->IPConnectButton->BackColor = System::Drawing::Color::Gold;
			this->IPConnectButton->Location = System::Drawing::Point(320, 5);
			this->IPConnectButton->Name = L"IPConnectButton";
			this->IPConnectButton->Size = System::Drawing::Size(75, 23);
			this->IPConnectButton->TabIndex = 2;
			this->IPConnectButton->Text = L"Connect";
			this->IPConnectButton->UseVisualStyleBackColor = false;
			this->IPConnectButton->Click += gcnew System::EventHandler(this, &MyForm::IPConnectButton_Click);
			// 
			// MainTextBox
			// 
			this->MainTextBox->BackColor = System::Drawing::Color::LightBlue;
			this->MainTextBox->Location = System::Drawing::Point(15, 76);
			this->MainTextBox->Name = L"MainTextBox";
			this->MainTextBox->Size = System::Drawing::Size(380, 488);
			this->MainTextBox->TabIndex = 3;
			this->MainTextBox->Text = L"";
			// 
			// SendTextBox
			// 
			this->SendTextBox->Font = (gcnew System::Drawing::Font(L"±¼¸²", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->SendTextBox->Location = System::Drawing::Point(15, 570);
			this->SendTextBox->Name = L"SendTextBox";
			this->SendTextBox->Size = System::Drawing::Size(299, 96);
			this->SendTextBox->TabIndex = 4;
			this->SendTextBox->Text = L"";
			// 
			// SendButton
			// 
			this->SendButton->BackColor = System::Drawing::Color::Gold;
			this->SendButton->Location = System::Drawing::Point(320, 570);
			this->SendButton->Name = L"SendButton";
			this->SendButton->Size = System::Drawing::Size(75, 34);
			this->SendButton->TabIndex = 5;
			this->SendButton->Text = L"Send";
			this->SendButton->UseVisualStyleBackColor = false;
			this->SendButton->Click += gcnew System::EventHandler(this, &MyForm::SendButton_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// UserNameLabel
			// 
			this->UserNameLabel->AutoSize = true;
			this->UserNameLabel->Location = System::Drawing::Point(12, 46);
			this->UserNameLabel->Name = L"UserNameLabel";
			this->UserNameLabel->Size = System::Drawing::Size(85, 15);
			this->UserNameLabel->TabIndex = 6;
			this->UserNameLabel->Text = L"NickName : ";
			// 
			// NickNameTextBox
			// 
			this->NickNameTextBox->Location = System::Drawing::Point(94, 43);
			this->NickNameTextBox->Name = L"NickNameTextBox";
			this->NickNameTextBox->Size = System::Drawing::Size(220, 25);
			this->NickNameTextBox->TabIndex = 7;
			// 
			// NickNameSetButton
			// 
			this->NickNameSetButton->BackColor = System::Drawing::Color::Gold;
			this->NickNameSetButton->Location = System::Drawing::Point(320, 43);
			this->NickNameSetButton->Name = L"NickNameSetButton";
			this->NickNameSetButton->Size = System::Drawing::Size(75, 23);
			this->NickNameSetButton->TabIndex = 8;
			this->NickNameSetButton->Text = L"Set";
			this->NickNameSetButton->UseVisualStyleBackColor = false;
			this->NickNameSetButton->Click += gcnew System::EventHandler(this, &MyForm::NickNameSetButton_Click);
			// 
			// FontLinkLabel
			// 
			this->FontLinkLabel->AutoSize = true;
			this->FontLinkLabel->LinkColor = System::Drawing::Color::Black;
			this->FontLinkLabel->Location = System::Drawing::Point(324, 620);
			this->FontLinkLabel->Name = L"FontLinkLabel";
			this->FontLinkLabel->Size = System::Drawing::Size(36, 15);
			this->FontLinkLabel->TabIndex = 9;
			this->FontLinkLabel->TabStop = true;
			this->FontLinkLabel->Text = L"Font";
			this->FontLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::FontLinkLabel_LinkClicked);
			// 
			// ColorLickLabel
			// 
			this->ColorLickLabel->AutoSize = true;
			this->ColorLickLabel->LinkColor = System::Drawing::Color::Black;
			this->ColorLickLabel->Location = System::Drawing::Point(324, 651);
			this->ColorLickLabel->Name = L"ColorLickLabel";
			this->ColorLickLabel->Size = System::Drawing::Size(71, 15);
			this->ColorLickLabel->TabIndex = 10;
			this->ColorLickLabel->TabStop = true;
			this->ColorLickLabel->Text = L"TextColor";
			this->ColorLickLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::ColorLickLabel_LinkClicked);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightBlue;
			this->ClientSize = System::Drawing::Size(407, 693);
			this->Controls->Add(this->ColorLickLabel);
			this->Controls->Add(this->FontLinkLabel);
			this->Controls->Add(this->NickNameSetButton);
			this->Controls->Add(this->NickNameTextBox);
			this->Controls->Add(this->UserNameLabel);
			this->Controls->Add(this->SendButton);
			this->Controls->Add(this->SendTextBox);
			this->Controls->Add(this->MainTextBox);
			this->Controls->Add(this->IPConnectButton);
			this->Controls->Add(this->IPTextBox);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"SocketChat";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:Socket^client;
	public:IPEndPoint^IP;
	public:Thread^clientThread;
	public:String^nickname;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		client = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}

	private: System::Void IPConnectButton_Click(System::Object^  sender, System::EventArgs^  e) {
		IP = gcnew IPEndPoint(IPAddress::Parse(IPTextBox->Text), 1004);
		try {
			IP = gcnew IPEndPoint(IPAddress::Parse(IPTextBox->Text), 1004);
			client->Connect(IP);

			backgroundWorker1->RunWorkerAsync();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);;
		}
	}

	private: System::Void NickNameSetButton_Click(System::Object^  sender, System::EventArgs^  e) {
		nickname = NickNameTextBox->Text + " : ";
	}

	private: System::Void FontLinkLabel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		if (fontDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			SendTextBox->Font = fontDialog1->Font;
		}
	}

	private: System::Void ColorLickLabel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			SendTextBox->ForeColor = colorDialog1->Color;
		}
	}

	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		while (true) {
			array<unsigned char>^buf = gcnew array<unsigned char>(1024);
			int temp = client->Receive(buf);
			FormatterText::StructChat^str = gcnew FormatterText::StructChat();
			str = Deserialize(buf);
			AddText(str->textChat, str->myFont, str->myColor);
		}
	}

	private:void AddText(String^ text, System::Drawing::Font^ font, System::Drawing::Color^ color) {
		MainTextBox->SelectionFont = font;
		MainTextBox->SelectionColor = (Color)color;
		MainTextBox->AppendText(text + "\n");
		MainTextBox->ScrollToCaret();
	}

	public: array<unsigned char, 1>^ Serialize(FormatterText::StructChat^ str)
	{
		MemoryStream^ ms = gcnew MemoryStream();
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		bf->Serialize(ms, str);
		return ms->ToArray();
	}

	public: FormatterText::StructChat^ Deserialize(array<unsigned char>^ buff)
	{
		 MemoryStream^ ms = gcnew MemoryStream(buff);
		 BinaryFormatter^ bf = gcnew BinaryFormatter();
		return (FormatterText::StructChat^)bf->Deserialize(ms);
	}

	private: System::Void SendButton_Click(System::Object^  sender, System::EventArgs^  e) {
		FormatterText::StructChat^ str = gcnew FormatterText::StructChat();
		str->textChat = nickname + SendTextBox->Text;
		str->myColor = SendTextBox->ForeColor;
		str->myFont = SendTextBox->Font;
		array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
		MemoryStream^ ms = gcnew MemoryStream();
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		bf->Serialize(ms, str);
		buf = ms->ToArray();
		client->Send(buf, buf->Length, SocketFlags::None);
	}
};
}
