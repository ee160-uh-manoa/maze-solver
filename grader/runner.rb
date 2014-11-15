class Grader::Runner
  class << self
    attr_reader :executable, :results_folder
  end
  @executable     = 'maze_solver'
  @results_folder = 'results'
  
  attr_reader :maze_file, :solver_file
  
  def initialize(maze_file, solver_file)
    @maze_file   = maze_file
    @solver_file = solver_file
  end
  
  def check
    prepare
    run
    record_results
    clean_up
  end
  
  private
  
  def solver
    @solver ||= File.basename(solver_file, File.extname(solver_file))  
  end

  def prepare
    `make clean`
    `make SOLVER=#{Shellwords.escape(solver)}`
  end
  
  def run
    `./#{self.class.executable} #{maze}`
  end
  
  def record_results
    create_maze_result_folder
    `cp -- *.result #{maze_result_folder}/#{score}_#{solver}`
  end
  
  def score
    File.basename(result_file, File.extname(result_file))
  end
  
  def result_file
    Dir.glob('*.result').first
  end
  
  def maze
    @maze ||= File.basename(maze_file, File.extname(maze_file))
  end
  
  def create_maze_result_folder
    `mkdir #{maze_result_folder}`
  end
  
  def maze_result_folder
    "#{self.class.results_folder}/#{maze}"
  end
  
  def clean_up
    `rm -- *.result`
    `rm #{self.class.executable}`
  end
end