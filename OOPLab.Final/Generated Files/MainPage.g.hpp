﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#pragma warning(push)
#pragma warning(disable: 4100) // unreferenced formal parameter

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "MainPage.xaml.h"

void ::OOPLab_Final::MainPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///MainPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::OOPLab_Final::MainPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
    case 2:
        {
            this->mainScreen = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
        }
        break;
    case 3:
        {
            this->backButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->backButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::OOPLab_Final::MainPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::back_Click);
        }
        break;
    case 4:
        {
            this->searchBar = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 5:
        {
            this->tittle = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
        }
        break;
    case 6:
        {
            this->searchButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->searchButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::OOPLab_Final::MainPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::searchButton_Click);
        }
        break;
    case 7:
        {
            this->gridNoteView = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
        }
        break;
    case 8:
        {
            this->addNewNoteButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->addNewNoteButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::OOPLab_Final::MainPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::addNewNote_Click);
        }
        break;
    case 9:
        {
            this->opSplitView = safe_cast<::Windows::UI::Xaml::Controls::SplitView^>(__target);
        }
        break;
    case 10:
        {
            this->optionButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->optionButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::OOPLab_Final::MainPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::opButton_Click);
        }
        break;
    case 11:
        {
            this->splitViewDelete = safe_cast<::Windows::UI::Xaml::Controls::SplitView^>(__target);
        }
        break;
    case 12:
        {
            this->rubbishBin = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->rubbishBin))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::OOPLab_Final::MainPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::deleteNote_Click);
        }
        break;
    case 13:
        {
            this->SaveButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->SaveButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::OOPLab_Final::MainPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::saveButton_Click);
        }
        break;
    case 14:
        {
            this->RubbishBin = safe_cast<::Windows::UI::Xaml::Controls::Image^>(__target);
        }
        break;
    case 15:
        {
            this->stackPanelDeleteNote = safe_cast<::Windows::UI::Xaml::Controls::StackPanel^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::StackPanel^>(this->stackPanelDeleteNote))->Tapped += ref new ::Windows::UI::Xaml::Input::TappedEventHandler(this, (void (::OOPLab_Final::MainPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::Input::TappedRoutedEventArgs^))&MainPage::stackPanelDeleteNote_Tapped);
        }
        break;
    case 16:
        {
            this->FillRec_1 = safe_cast<::Windows::UI::Xaml::Shapes::Rectangle^>(__target);
        }
        break;
    case 17:
        {
            this->FillRec_2 = safe_cast<::Windows::UI::Xaml::Shapes::Rectangle^>(__target);
        }
        break;
    case 18:
        {
            this->FillRec_3 = safe_cast<::Windows::UI::Xaml::Shapes::Rectangle^>(__target);
        }
        break;
    case 19:
        {
            this->textBoxAddTag = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
        }
        break;
    case 20:
        {
            this->addTagButton = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
            (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->addTagButton))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::OOPLab_Final::MainPage::*)
                (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::addTagButton_Click);
        }
        break;
    case 21:
        {
            this->gridAddTag = safe_cast<::Windows::UI::Xaml::Controls::StackPanel^>(__target);
        }
        break;
    case 22:
        {
            this->FillRec_4 = safe_cast<::Windows::UI::Xaml::Shapes::Rectangle^>(__target);
        }
        break;
    case 23:
        {
            this->FillRec_5 = safe_cast<::Windows::UI::Xaml::Shapes::Rectangle^>(__target);
        }
        break;
    case 24:
        {
            this->borderNoteView = safe_cast<::Windows::UI::Xaml::Controls::Border^>(__target);
        }
        break;
    case 25:
        {
            this->scrollNoteView = safe_cast<::Windows::UI::Xaml::Controls::ScrollViewer^>(__target);
        }
        break;
    case 26:
        {
            this->stackPanelViewNote = safe_cast<::Windows::UI::Xaml::Controls::StackPanel^>(__target);
        }
        break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::OOPLab_Final::MainPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

#pragma warning(pop)


