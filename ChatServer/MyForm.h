#pragma once

namespace ChatServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace FormatterText;
	using namespace System::Collections::Generic;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;

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
	protected:

	private: System::Windows::Forms::Button^  ConnectButton;

	private: System::Windows::Forms::RichTextBox^  MainTextBox;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

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
			this->ConnectButton = (gcnew System::Windows::Forms::Button());
			this->MainTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP adress : ";
			// 
			// IPTextBox
			// 
			this->IPTextBox->Location = System::Drawing::Point(95, 13);
			this->IPTextBox->Name = L"IPTextBox";
			this->IPTextBox->Size = System::Drawing::Size(219, 25);
			this->IPTextBox->TabIndex = 1;
			// 
			// ConnectButton
			// 
			this->ConnectButton->Location = System::Drawing::Point(320, 13);
			this->ConnectButton->Name = L"ConnectButton";
			this->ConnectButton->Size = System::Drawing::Size(75, 23);
			this->ConnectButton->TabIndex = 2;
			this->ConnectButton->Text = L"Connect";
			this->ConnectButton->UseVisualStyleBackColor = true;
			this->ConnectButton->Click += gcnew System::EventHandler(this, &MyForm::ConnectButton_Click);
			// 
			// MainTextBox
			// 
			this->MainTextBox->Location = System::Drawing::Point(12, 44);
			this->MainTextBox->Name = L"MainTextBox";
			this->MainTextBox->Size = System::Drawing::Size(383, 424);
			this->MainTextBox->TabIndex = 3;
			this->MainTextBox->Text = L"";
			this->MainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MainTextBox_KeyPress);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(407, 480);
			this->Controls->Add(this->MainTextBox);
			this->Controls->Add(this->ConnectButton);
			this->Controls->Add(this->IPTextBox);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Server";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void MainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			e->Handled = true;
	}

	public: static Socket^server;
	public: static List<Socket^>^listClient = gcnew List<Socket^>();
	public: static IPEndPoint^IP;
	public: static Thread^threadClient;

	private: System::Void ConnectButton_Click(System::Object^  sender, System::EventArgs^  e) {
		IP = gcnew IPEndPoint(IPAddress::Parse(IPTextBox->Text),1004);
		backgroundWorker1->WorkerSupportsCancellation = true;
		backgroundWorker1->RunWorkerAsync();
	}
	
	private: static void client(Object^obj) {
		Socket^ socket = (Socket^)obj;
		while (true) {
			try {
				array<unsigned char>^buff = gcnew array<unsigned char>(1024);
				int temp = socket->Receive(buff);

				for each(Socket^ sock in listClient) {
					try {
						sock->Send(buff, buff->Length, SocketFlags::None);
					}
					catch (Exception^ ex) {

					}
				}
			}
			catch (Exception^ ex) {
				listClient->Remove(socket);
				return;
			}
		}
	}

	private:void AddTextToMainTextBox(String ^text, System::Drawing::Font^ font, System::Drawing::Color^ color) {

		MainTextBox->SelectionFont = font;
		MainTextBox->SelectionColor = (Color)color;
		MainTextBox->AppendText(text + "\n");
	}
	
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}

	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		server->Bind(IP);
		server->Listen(10);
		String^text = "The server is operational.";
		System::Drawing::Font^font = gcnew System::Drawing::Font("¸¼Àº °íµñ", 9, FontStyle::Bold);
		System::Drawing::Color^color = Color::Red;
		AddTextToMainTextBox(text, font, color);

		while (true) {
			Socket^clientAccept = server->Accept();
			listClient->Add(clientAccept);

			threadClient = gcnew Thread(gcnew ParameterizedThreadStart(ChatServer::MyForm::client));
			threadClient->IsBackground = true;
			threadClient->Start(clientAccept);

			String^TextTemp = "Client connected -> " + clientAccept->RemoteEndPoint->ToString();
			System::Drawing::Font^FontTemp = gcnew System::Drawing::Font("¸¼Àº °íµñ", 9, FontStyle::Bold);
			System::Drawing::Color^ColrTemp = Color::Red;
			AddTextToMainTextBox(TextTemp, FontTemp, ColrTemp);
		}
	}
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (backgroundWorker1->IsBusy) {
			backgroundWorker1->CancelAsync();
		}
	}
};
}
