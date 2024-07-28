#pragma once



namespace mgui {


    struct UUIDKey { 
        unsigned char raw[16]; 

        static UUIDKey Generate();
        static UUIDKey GenerateZeroed();

        size_t GetHashCode() const;
        std::string ToString() const;

        bool operator==(const UUIDKey& other) const;
        bool operator>(const UUIDKey& other) const;
    };
}

