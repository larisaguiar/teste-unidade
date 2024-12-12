import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.stream.Collectors;

class RepositorioMemoria implements Repositorio {

  private Map<String, Livro> acervo;
  private Map<Livro, Usuario> emprestimos;

  public RepositorioMemoria (){
    acervo = new HashMap<String, Livro>();
    emprestimos = new HashMap<Livro, Usuario>();
  }

  public void adicionarLivroAcervo(String isbn, Livro livro) {
    if (acervo.containsKey(isbn)) {
        return;  // Não adiciona o livro se o ISBN já estiver no acervo
    }
    acervo.put(livro.getISBN(), livro);
  }

  public boolean livroEstaEmprestado(Livro livro) {
    return emprestimos.containsKey(livro);
  }

  public void emprestarLivro(Livro livro, Usuario usuario) throws ExcecaoLivroEmprestado {
    if (livroEstaEmprestado(livro)) {
        throw new ExcecaoLivroEmprestado();  // Lança a exceção se o livro já foi emprestado
    }
    emprestimos.put(livro, usuario);
  }

  public void receberLivroEmprestado(Livro livro) {
    if (!livroEstaEmprestado(livro)) {
        return;  // Ou lançar uma exceção, caso seja necessário
    }
    emprestimos.remove(livro);  // Remove o livro da lista de empréstimos
  }

  public List<Livro> livrosEmprestadosUsuario(Usuario usuario) {
    return emprestimos.entrySet().stream()
                      .filter(e -> e.getValue() == usuario)
                      .map(Map.Entry::getKey)
                      .collect(Collectors.toList());
  }
}
