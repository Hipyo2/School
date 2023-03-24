defmodule InClass.Company.Assignment do
  use Ecto.Schema
  import Ecto.Changeset
  alias InClass.Company.{Developer,Task,Status}

  schema "assignments" do
    field :due_date, :string
    field :name, :string
    belongs_to(:status, Status)
    belongs_to(:developer, Developer)
    belongs_to(:task, Task)
    timestamps()
  end

  @doc false
  def changeset(assignment, attrs) do
    assignment
    |> cast(attrs, [:name, :due_date, :status_id, :developer_id, :task_id])
    |> validate_required([:name, :due_date, :status_id, :developer_id, :task_id])
  end
end
