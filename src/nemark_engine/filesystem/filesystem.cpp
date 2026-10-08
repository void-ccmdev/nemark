#include "filesystem.h"

#include "nemark_engine/nemark_engine.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

using namespace Nemark;

//----------------
//  FileSystem
//----------------

void FileSystem::writeFile(File file, std::string& content)
{
    std::filesystem::path directory = file.path;
    std::filesystem::path filePath = directory / file.name;

    std::error_code error;
    std::filesystem::create_directories(directory, error);

    if (error) {
        Nemark::OutputServer output;
        output.printErr("Couldn't create directory '" +
                        directory.string() + "': " +
                        error.message());
        return;
    }

    std::ofstream newFile(filePath);

    if (!newFile.is_open()) {
        Nemark::OutputServer output;
        output.printErr("Couldn't open file '" + filePath.string() + "'");
        return;
    }

    newFile << content;
}

void FileSystem::appendToFile(File file, std::string& content)
{
    std::filesystem::path directory = file.path;
    std::filesystem::path filePath = directory / file.name;

    std::error_code error;
    std::filesystem::create_directories(directory, error);

    if (error) {
        Nemark::OutputServer output;
        output.printErr("Couldn't create directory '" +
                        directory.string() + "': " +
                        error.message());
        return;
    }

    std::ofstream targetFile(filePath, std::ios::app);

    if (!targetFile.is_open()) {
        Nemark::OutputServer output;
        output.printErr("Couldn't open file for writing.");
        return;
    }

    targetFile << content;
}

std::string FileSystem::readFile(File file)
{
    std::ifstream read_file(file.path + file.name);

    if (!read_file.is_open()) {
        Nemark::OutputServer output;
        output.printErr("Couldn't open file '" + file.name + "' at '" + file.path + "'");
        return {};
    }

    std::stringstream content;
    content << read_file.rdbuf();

    return content.str();
}

void FileSystem::removeFile(File file)
{
    std::filesystem::path filePath = std::filesystem::path(file.path) / file.name;

    std::error_code error;
    bool removed = std::filesystem::remove(filePath, error);

    if (error) {
        Nemark::OutputServer output;
        output.printErr(
            "Couldn't remove file '" +
            filePath.string() +
            "': " +
            error.message()
        );
        return;
    }

    if (!removed) {
        Nemark::OutputServer output;
        output.printErr(
            "File does not exist: " + filePath.string()
        );
        return;
    }
}

File FileSystem::createFile(std::string& name, std::string& path)
{
    File file;
    file.name = name;
    file.path = path;

    return file;
}

void FileSystem::createFolder(std::string& name, std::string& path)
{
    std::filesystem::path folderPath = std::filesystem::path(path) / name;
    std::error_code err;
    std::filesystem::create_directories(folderPath, err);
}

void FileSystem::removeFolder(std::string& path)
{
    std::filesystem::path folderPath = std::filesystem::path(path);
    std::error_code err;
    bool removed = std::filesystem::remove(path);

    if(!removed) {
        Nemark::OutputServer output;
        output.printErr(
            "Couldn't remove: " + folderPath.string()
        );
        return;
    }
}