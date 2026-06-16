class AffineCipher : public Cipher {
public:
    AffineCipher(int a, int b);

    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;

private:
    int a_;
    int b_;

    bool isValidA(int a) const;
};