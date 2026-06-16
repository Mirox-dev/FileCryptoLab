class XorCipher : public Cipher {
public:
    explicit XorCipher(std::string key);

    std::string encrypt(const std::string& text) override;
    std::string decrypt(const std::string& text) override;

private:
    std::string key_;
};